#include "stdafx.h"
#include "Inventor.h"
#include "PartBuilders.h"
#include "Utility.h"

void BuildBearing(double indiametr, double outdiametr, double B) {
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

	p_PartDocumnet->DisplayName = _T("Подшипник"); // Название детали

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

	p_TransManager->raw_StartTransaction(Doc, _T("Подшипник"), &p_Transaction);

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

	SketchPointPtr points1[14];
	SketchPoints *p_Points;
	SketchLines *p_Lines;
	SketchLinePtr Lines1[10];
	SketchArcs *p_Arc;
	SketchArcPtr Arc1[2];

	p_sketch1->get_SketchPoints(&p_Points);
	p_sketch1->get_SketchLines(&p_Lines);
	p_sketch1->get_SketchArcs(&p_Arc);

	double DofBall ((outdiametr - indiametr) / 2);
	double CofMidCirc;
	CofMidCirc = (outdiametr-(outdiametr - indiametr)/2)*pi;
	double Centre = (outdiametr - (outdiametr - indiametr) / 2);
	points1[0] = p_Points->MethodAdd(p_TransGeom->MethodCreatePoint2d(mm_to_cm(-B/2), mm_to_cm(indiametr / 2)), false);
	points1[1] = p_Points->MethodAdd(p_TransGeom->MethodCreatePoint2d(mm_to_cm(B/2), mm_to_cm(indiametr / 2)), false);
	points1[2] = p_Points->MethodAdd(p_TransGeom->MethodCreatePoint2d(mm_to_cm(-B/2), mm_to_cm(outdiametr / 2)), false);
	points1[3] = p_Points->MethodAdd(p_TransGeom->MethodCreatePoint2d(mm_to_cm(B/2), mm_to_cm(outdiametr / 2)), false);
	points1[4] = p_Points->MethodAdd(p_TransGeom->MethodCreatePoint2d(mm_to_cm(B/2), mm_to_cm(indiametr/2+DofBall/ 2.8)), false);
	points1[5] = p_Points->MethodAdd(p_TransGeom->MethodCreatePoint2d(mm_to_cm(-B/2), mm_to_cm(indiametr/2 + DofBall / 2.8)), false);
	points1[6] = p_Points->MethodAdd(p_TransGeom->MethodCreatePoint2d(0, mm_to_cm((indiametr/2+DofBall/2))), false);
	points1[7] = p_Points->MethodAdd(p_TransGeom->MethodCreatePoint2d(mm_to_cm (-B/2), mm_to_cm((outdiametr/2-DofBall/ 2.8))), false);
	points1[8] = p_Points->MethodAdd(p_TransGeom->MethodCreatePoint2d(mm_to_cm(B/2), mm_to_cm((outdiametr/2 - DofBall/ 2.8))), false);
	points1[9] = p_Points->MethodAdd(p_TransGeom->MethodCreatePoint2d(0, mm_to_cm((outdiametr/2-DofBall/2))), false);
	points1[10] = p_Points->MethodAdd(p_TransGeom->MethodCreatePoint2d(mm_to_cm(-B/2+ DofBall / 6.5), mm_to_cm(indiametr / 2 + DofBall / 2.8)), false);
	points1[11] = p_Points->MethodAdd(p_TransGeom->MethodCreatePoint2d(mm_to_cm(B/2-DofBall/6.5), mm_to_cm(indiametr / 2 + DofBall / 2.8)), false);
	points1[12] = p_Points->MethodAdd(p_TransGeom->MethodCreatePoint2d(mm_to_cm(-B / 2 + DofBall / 6.5), mm_to_cm((outdiametr / 2 - DofBall / 2.8))), false);
	points1[13] = p_Points->MethodAdd(p_TransGeom->MethodCreatePoint2d(mm_to_cm(B / 2 - DofBall / 6.5), mm_to_cm((outdiametr / 2 - DofBall / 2.8))), false);

	Lines1[0] = p_Lines->MethodAddByTwoPoints(points1[0], points1[1]);
	Lines1[1] = p_Lines->MethodAddByTwoPoints(points1[1], points1[4]);
	Lines1[2] = p_Lines->MethodAddByTwoPoints(points1[0], points1[5]);
	Lines1[3] = p_Lines->MethodAddByTwoPoints(points1[3], points1[2]);
	Lines1[4] = p_Lines->MethodAddByTwoPoints(points1[2], points1[7]);
	Lines1[5] = p_Lines->MethodAddByTwoPoints(points1[3], points1[8]);
	Lines1[6] = p_Lines->MethodAddByTwoPoints(points1[5], points1[10]);
	Lines1[7] = p_Lines->MethodAddByTwoPoints(points1[4], points1[11]);
	Lines1[8] = p_Lines->MethodAddByTwoPoints(points1[7], points1[12]);
	Lines1[9] = p_Lines->MethodAddByTwoPoints(points1[13], points1[8]);

	Arc1[0]=p_Arc->MethodAddByCenterStartEndPoint(points1[6], points1[10], points1[11], true);
	Arc1[1] = p_Arc->MethodAddByCenterStartEndPoint(points1[9], points1[12], points1[13], false);

	Profile *p_Profile1;
	Profiles *p_Profiles1;

	p_sketch1->get_Profiles(&p_Profiles1);
	p_Profiles1->raw__AddForSolid(&p_Profile1);
	
	RevolveFeatures *ftRevolve1;
	p_partFeatures->get_RevolveFeatures(&ftRevolve1);
	ftRevolve1->MethodAddFull(p_Profile1, p_workAxes->GetItem(1), kNewBodyOperation);


	PlanarSketch *p_Sketch2;

	p_plannarSketches->raw_Add(
		p_workPlanes->GetItem(2),
		false,
		&p_Sketch2
	);
	
	SketchPointPtr points2[3];
	SketchPoints *p_Points2;
	SketchLines *p_Lines2;
	SketchLinePtr Lines2[1];
	SketchArcs *p_Arc2;
	SketchArcPtr Arc2[1];

	p_Sketch2->get_SketchPoints(&p_Points2);
	p_Sketch2->get_SketchLines(&p_Lines2);
	p_Sketch2->get_SketchArcs(&p_Arc2);

	points2[0] = p_Points2->MethodAdd(p_TransGeom->MethodCreatePoint2d(0, mm_to_cm(Centre/2+DofBall/2.5)), false);
	points2[1] = p_Points2->MethodAdd(p_TransGeom->MethodCreatePoint2d(0, mm_to_cm(Centre/2 - DofBall/2.5)), false);
	points2[2] = p_Points2->MethodAdd(p_TransGeom->MethodCreatePoint2d(0, mm_to_cm(Centre/2)), false);

	Lines2[0] = p_Lines2->MethodAddByTwoPoints(points2[0], points2[1]);

	Arc2[0] = p_Arc2->MethodAddByCenterStartEndPoint(points2[2], points2[0], points2[1], true);

	
	Profile *p_Profile2;
	Profiles *p_Profiles2;

	p_Sketch2->get_Profiles(&p_Profiles2);
	p_Profiles2->raw__AddForSolid(&p_Profile2);

	RevolveFeatures *ftRevolve2;
	p_partFeatures->get_RevolveFeatures(&ftRevolve2);
	auto Rev = ftRevolve2->MethodAddFull(p_Profile2, p_workAxes->GetItem(3), kNewBodyOperation);

	int N;
	for (N = 6; DofBall*N < CofMidCirc; N++)
	{
		N = N++;
	}

	ObjectCollection *p_collection1;

	p_invApp->TransientObjects->raw_CreateObjectCollection(vtMissing, &p_collection1);
	p_collection1->MethodAdd(Rev);
	p_collection1->MethodAdd(Rev);

	p_circPatFeature->MethodAdd(
		p_collection1,
		p_workAxes->GetItem(1),
		true,
		N-1,
		"360",
		true,
		kIdenticalCompute
	);
	return;
	
	// Сохранение детали
	// TODO: Задавать пользовательский путь

	TCHAR szDirectory[MAX_PATH];
	::GetCurrentDirectory(sizeof(szDirectory) - 1, szDirectory);
	p_PartDocumnet->MethodSaveAs(szDirectory + _bstr_t("\\Сборка\\Подшипник.ipt"), false);
}