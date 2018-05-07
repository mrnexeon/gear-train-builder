#include "stdafx.h"
#include "Inventor.h"
#include "PartBuilders.h"
#include "Utility.h"

void BuildGear(double outerDiameter, double insideDiameter, double thickness, unsigned cogCount) {
	// Указатель на документ, представляющий деталь
	PartDocumentPtr p_PartDocumnet;

	// Указатель на деталь и ее содержимое (эскизы, оси и т.д.)
	PartComponentDefinition *p_PartComponentDef;

	// Указатель на менеджер по построению геометрии
	TransientGeometry *p_TransGeom;

	// Указатель на менеджер по построению детали
	TransactionManagerPtr p_TransManager;

	// Объект представления хода детали
	Transaction *p_Transaction;

	Document *Doc; // Файл проекта в Inventor
	PlanarSketches *p_plannarSketches; // Эскизы
	WorkPlanes *p_workPlanes; // Рабочие плоскости
	PartFeatures *p_partFeatures; // Инструменты
	WorkAxes *p_workAxes; // Оси
	WorkPoints *p_workPoints; // Точки

	p_PartDocumnet = p_invApp->Documents->MethodAdd( // Создание детали
		kPartDocumentObject,
		p_invApp->FileManager->MethodGetTemplateFile(
			kPartDocumentObject,
			kMetricSystemOfMeasure, // Метрическая СИ
			kGOST_DraftingStandard),
		true
	);

	p_PartDocumnet->DisplayName = _T("Шестерня"); // Название детали

	// Инициализация указателей

	p_TransManager = p_invApp->GetTransactionManager();
	p_invApp->get_TransientGeometry(&p_TransGeom);
	Doc = CComQIPtr<Document>(p_PartDocumnet); 
	p_PartDocumnet->get_ComponentDefinition(&p_PartComponentDef);

	// Инициализация указателей на содержимое детали

	p_PartComponentDef->get_Sketches(&p_plannarSketches);
	p_PartComponentDef->get_WorkPlanes(&p_workPlanes);
	p_PartComponentDef->get_Features(&p_partFeatures);
	p_PartComponentDef->get_WorkAxes(&p_workAxes);
	p_PartComponentDef->get_WorkPoints(&p_workPoints);

	p_TransManager->raw_StartTransaction(Doc, _T("Шестереня"), &p_Transaction);

	/* TODO: Построить деталь по параметрам, сохранить деталь в папке сборки */

	ExtrudeFeatures *p_ExtrudeFeatures;
	p_partFeatures->get_ExtrudeFeatures(&p_ExtrudeFeatures);
	CircularPatternFeatures *p_circPatFeature;
	p_partFeatures->get_CircularPatternFeatures(&p_circPatFeature);
	MirrorFeatures *p_MirrorFeatures;
	p_partFeatures->get_MirrorFeatures(&p_MirrorFeatures);
	FilletFeatures *p_FilletFeatures;
	p_partFeatures->get_FilletFeatures(&p_FilletFeatures);
	ChamferFeatures *p_ChamferFeatures;
	p_partFeatures->get_ChamferFeatures(&p_ChamferFeatures);

	PlanarSketch *p_sketch1;

	p_plannarSketches->raw_Add(
		p_workPlanes->GetItem(2),
		false,
		&p_sketch1
	);

	SketchCircles *p_Circles;
	p_sketch1->get_SketchCircles(&p_Circles);

	p_Circles->MethodAddByCenterRadius(p_TransGeom->MethodCreatePoint2d(0, 0), mm_to_cm(outerDiameter / 2.0));
	p_Circles->MethodAddByCenterRadius(p_TransGeom->MethodCreatePoint2d(0, 0), mm_to_cm((outerDiameter / 2.0) * 0.875));
	p_Circles->MethodAddByCenterRadius(p_TransGeom->MethodCreatePoint2d(0, 0), mm_to_cm((insideDiameter / 2.0) * 1.5));
	p_Circles->MethodAddByCenterRadius(p_TransGeom->MethodCreatePoint2d(0, 0), mm_to_cm(insideDiameter / 2.0));

	Profile *p_Profile1;
	Profiles *p_Profiles;

	p_sketch1->get_Profiles(&p_Profiles);
	p_Profiles->raw__AddForSolid(&p_Profile1);

	p_ExtrudeFeatures->MethodAddByDistanceExtent(p_Profile1, mm_to_cm(thickness), kSymmetricExtentDirection, kNewBodyOperation);

	PlanarSketch *p_sketch2;

	p_plannarSketches->raw_Add(
		p_workPlanes->GetItem(2),
		false,
		&p_sketch2
	);

	p_sketch2->get_SketchCircles(&p_Circles);

	p_Circles->MethodAddByCenterRadius(p_TransGeom->MethodCreatePoint2d(0, 0), mm_to_cm((outerDiameter / 2.0) * 0.875));
	p_Circles->MethodAddByCenterRadius(p_TransGeom->MethodCreatePoint2d(0, 0), mm_to_cm((outerDiameter / 2.0) * 0.8));
	p_Circles->MethodAddByCenterRadius(p_TransGeom->MethodCreatePoint2d(0, 0), mm_to_cm((insideDiameter / 2.0) * 1.8));
	p_Circles->MethodAddByCenterRadius(p_TransGeom->MethodCreatePoint2d(0, 0), mm_to_cm((insideDiameter / 2.0) * 1.5));

	Profile *p_Profile2;

	p_sketch2->get_Profiles(&p_Profiles);
	p_Profiles->raw__AddForSolid(&p_Profile2);

	auto result1 = p_ExtrudeFeatures->MethodAddByDistanceExtent(p_Profile2, mm_to_cm(thickness * 0.75), kSymmetricExtentDirection, kJoinOperation);

	EdgeCollection *p_edgeCollection;
	p_invApp->TransientObjects->raw_CreateEdgeCollection(vtMissing, &p_edgeCollection);

	p_edgeCollection->raw_Add(result1->GetStartFaces()->GetItem(1)->GetEdges()->GetItem(2));
	p_edgeCollection->raw_Add(result1->GetStartFaces()->GetItem(2)->GetEdges()->GetItem(1));
	p_edgeCollection->raw_Add(result1->GetEndFaces()->GetItem(1)->GetEdges()->GetItem(2));
	p_edgeCollection->raw_Add(result1->GetEndFaces()->GetItem(2)->GetEdges()->GetItem(1));

	// TODO: Параметризировать длину фаски
	p_ChamferFeatures->MethodAddUsingDistance(p_edgeCollection, mm_to_cm(2.0), false, false, false);

	PlanarSketch *p_sketch3;

	p_plannarSketches->raw_Add(
		p_workPlanes->GetItem(3),
		false,
		&p_sketch3
	);

	SketchPointPtr points1[12];
	SketchPoints *p_Points;
	SketchLines *p_Lines;

	p_sketch3->get_SketchPoints(&p_Points);
	p_sketch3->get_SketchLines(&p_Lines);

	double crossThick = thickness * 0.15;
	double crossLength = thickness * 0.75;

	points1[0] = p_Points->MethodAdd(p_TransGeom->MethodCreatePoint2d(mm_to_cm(-crossLength / 2.0), mm_to_cm(-crossThick / 2.0)), false);
	points1[1] = p_Points->MethodAdd(p_TransGeom->MethodCreatePoint2d(mm_to_cm(-crossLength / 2.0), mm_to_cm(crossThick / 2.0)), false);
	points1[2] = p_Points->MethodAdd(p_TransGeom->MethodCreatePoint2d(mm_to_cm(-crossThick / 2.0), mm_to_cm(crossThick / 2.0)), false);
	points1[3] = p_Points->MethodAdd(p_TransGeom->MethodCreatePoint2d(mm_to_cm(-crossThick / 2.0), mm_to_cm(crossLength / 2.0)), false);
	points1[4] = p_Points->MethodAdd(p_TransGeom->MethodCreatePoint2d(mm_to_cm(crossThick / 2.0), mm_to_cm(crossLength / 2.0)), false);
	points1[5] = p_Points->MethodAdd(p_TransGeom->MethodCreatePoint2d(mm_to_cm(crossThick / 2.0), mm_to_cm(crossThick / 2.0)), false);
	points1[6] = p_Points->MethodAdd(p_TransGeom->MethodCreatePoint2d(mm_to_cm(crossLength / 2.0), mm_to_cm(crossThick / 2.0)), false);
	points1[7] = p_Points->MethodAdd(p_TransGeom->MethodCreatePoint2d(mm_to_cm(crossLength / 2.0), mm_to_cm(-crossThick / 2.0)), false);
	points1[8] = p_Points->MethodAdd(p_TransGeom->MethodCreatePoint2d(mm_to_cm(crossThick / 2.0), mm_to_cm(-crossThick / 2.0)), false);
	points1[9] = p_Points->MethodAdd(p_TransGeom->MethodCreatePoint2d(mm_to_cm(crossThick / 2.0), mm_to_cm(-crossLength / 2.0)), false);
	points1[10] = p_Points->MethodAdd(p_TransGeom->MethodCreatePoint2d(mm_to_cm(-crossThick / 2.0), mm_to_cm(-crossLength / 2.0)), false);
	points1[11] = p_Points->MethodAdd(p_TransGeom->MethodCreatePoint2d(mm_to_cm(-crossThick / 2.0), mm_to_cm(-crossThick / 2.0)), false);

	p_Lines->MethodAddByTwoPoints(points1[0], points1[1]);
	p_Lines->MethodAddByTwoPoints(points1[1], points1[2]);
	p_Lines->MethodAddByTwoPoints(points1[2], points1[3]);
	p_Lines->MethodAddByTwoPoints(points1[3], points1[4]);
	p_Lines->MethodAddByTwoPoints(points1[4], points1[5]);
	p_Lines->MethodAddByTwoPoints(points1[5], points1[6]);
	p_Lines->MethodAddByTwoPoints(points1[6], points1[7]);
	p_Lines->MethodAddByTwoPoints(points1[7], points1[8]);
	p_Lines->MethodAddByTwoPoints(points1[8], points1[9]);
	p_Lines->MethodAddByTwoPoints(points1[9], points1[10]);
	p_Lines->MethodAddByTwoPoints(points1[10], points1[11]);
	p_Lines->MethodAddByTwoPoints(points1[11], points1[0]);

	Profile *p_Profile3;

	p_sketch3->get_Profiles(&p_Profiles);
	p_Profiles->raw__AddForSolid(&p_Profile3);

	auto result2 = p_ExtrudeFeatures->MethodAddByFromToExtent(p_Profile3, result1->GetSideFaces()->GetItem(1), true, result1->GetSideFaces()->GetItem(2), true, kJoinOperation);

	ObjectCollection *p_collection1;
	p_invApp->TransientObjects->raw_CreateObjectCollection(vtMissing, &p_collection1);
	p_collection1->MethodAdd(result2);

	p_circPatFeature->MethodAdd(
		p_collection1,
		p_workAxes->GetItem(2),
		true,
		cogCount * 0.25,
		"360",
		true,
		kIdenticalCompute
	);

	PlanarSketch *p_sketch4;

	p_plannarSketches->raw_Add(
		p_workPlanes->GetItem(2),
		false,
		&p_sketch4
	);

	p_sketch4->get_SketchLines(&p_Lines);
	p_sketch4->get_SketchPoints(&p_Points);

	SketchPointPtr points2[4];
	
	double cogHeigth = 20.0;

	points2[0] = p_Points->MethodAdd(p_TransGeom->MethodCreatePoint2d(0, mm_to_cm(outerDiameter / 2.0)), false);
	points2[1] = p_Points->MethodAdd(p_TransGeom->MethodCreatePoint2d(0, mm_to_cm((outerDiameter / 2.0) + cogHeigth)), false);
	points2[2] = p_Points->MethodAdd(p_TransGeom->MethodCreatePoint2d(mm_to_cm((outerDiameter / 2.0) * cos(deg_to_rad(90.0 + 2.0))), mm_to_cm((outerDiameter / 2.0) + cogHeigth)), false);
	points2[3] = p_Points->MethodAdd(p_TransGeom->MethodCreatePoint2d(
		mm_to_cm((outerDiameter / 2.0) * cos(deg_to_rad(90.0 + 4.0))), 
		mm_to_cm((outerDiameter / 2.0) * sin(deg_to_rad(90.0 + 4.0)))), 
	false);

	p_Lines->MethodAddByTwoPoints(points2[0], points2[1]);
	p_Lines->MethodAddByTwoPoints(points2[1], points2[2]);
	p_Lines->MethodAddByTwoPoints(points2[2], points2[3]);
	p_Lines->MethodAddByTwoPoints(points2[3], points2[0]);

	Profile *p_Profile4;

	p_sketch4->get_Profiles(&p_Profiles);
	p_Profiles->raw__AddForSolid(&p_Profile4);

	auto result3 = p_ExtrudeFeatures->MethodAddByDistanceExtent(p_Profile4, mm_to_cm(thickness), kSymmetricExtentDirection, kJoinOperation);

	p_edgeCollection->MethodClear();

	p_edgeCollection->raw_Add(result3->GetSideFaces()->GetItem(1)->GetEdges()->GetItem(1));
	p_edgeCollection->raw_Add(result3->GetSideFaces()->GetItem(1)->GetEdges()->GetItem(3));

	auto result4 = p_FilletFeatures->MethodAddSimple(p_edgeCollection, mm_to_cm(4.0), false, false, true, false, false, false);

	ObjectCollection *p_collection2;
	p_invApp->TransientObjects->raw_CreateObjectCollection(vtMissing, &p_collection2);
	p_collection2->MethodAdd(result3);
	p_collection2->MethodAdd(result4);

	auto result5 = p_MirrorFeatures->MethodAdd(p_collection2, result3->GetSideFaces()->GetItem(3), true, kIdenticalCompute);
	p_collection2->MethodAdd(result5);

	p_circPatFeature->MethodAdd(
		p_collection2,
		p_workAxes->GetItem(2),
		true,
		cogCount,
		"360",
		true,
		kIdenticalCompute
	);

	return;
}