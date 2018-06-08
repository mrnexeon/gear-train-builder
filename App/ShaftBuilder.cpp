#include "stdafx.h"
#include "Inventor.h"
#include "PartBuilders.h"
#include "Utility.h"

void BuildShaft(double length1,double length2, double diameterGear, double diameterBearing, double lengthGear /*30*/ , double lengthBearing /*20*/) {
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

	p_PartDocumnet->DisplayName = _T("Вал"); // Название детали

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

	p_TransManager->raw_StartTransaction(Doc, _T("Вал"), &p_Transaction);

	//double w1 = length1, w2 = length2, /*w3 = 100,*/ w6 = 130, w4 = 160, w5 = 180 , d1 = diametrBearing -20, d2 = diametrBearing, /*d3 = 68,*/ d4 = diameterGear, d5 = diametrBearing -10, wpz1 = 2, dp = 3;
	int dp = 3, wpz1 = 2;
	PlanarSketch *pSketch;
	p_plannarSketches->raw_Add(p_workPlanes->GetItem(3), false, &pSketch);
	SketchPointPtr point[14];
	SketchLinePtr lines[14];

	SketchPoints *skPoints;
	SketchLines *skLines;
	Profiles *skProfiles;

	pSketch->get_SketchPoints(&skPoints);
	pSketch->get_SketchLines(&skLines);
	pSketch->get_Profiles(&skProfiles);
	//15+3+10=28   10+5
	point[0] = skPoints->MethodAdd(p_TransGeom->MethodCreatePoint2d(0, 0), false);
	point[1] = skPoints->MethodAdd(p_TransGeom->MethodCreatePoint2d(0, mm_to_cm(diameterBearing/4.0)), false);
	point[2] = skPoints->MethodAdd(p_TransGeom->MethodCreatePoint2d(mm_to_cm(5), mm_to_cm(diameterBearing / 4.0)), false);
	point[3] = skPoints->MethodAdd(p_TransGeom->MethodCreatePoint2d(mm_to_cm(5), mm_to_cm(diameterBearing / 2.0)), false);	
	point[4] = skPoints->MethodAdd(p_TransGeom->MethodCreatePoint2d(mm_to_cm(5+ lengthBearing), mm_to_cm(diameterBearing/2.0)), false);	
	point[5] = skPoints->MethodAdd(p_TransGeom->MethodCreatePoint2d(mm_to_cm(5+lengthBearing), mm_to_cm(diameterBearing / 2.0+3)), false);
	point[6] = skPoints->MethodAdd(p_TransGeom->MethodCreatePoint2d(mm_to_cm(5 + lengthBearing/2.0+length1- lengthGear/2.0), mm_to_cm(diameterBearing / 2.0+3)), false);
	point[7] = skPoints->MethodAdd(p_TransGeom->MethodCreatePoint2d(mm_to_cm(5 + lengthBearing / 2.0 + length1 - lengthGear / 2.0), mm_to_cm(diameterGear/2.0)), false);	 
	point[8] = skPoints->MethodAdd(p_TransGeom->MethodCreatePoint2d(mm_to_cm(5 + lengthBearing / 2.0 + length1 + lengthGear / 2.0), mm_to_cm(diameterGear/2.0)), false);	 
	point[9] = skPoints->MethodAdd(p_TransGeom->MethodCreatePoint2d(mm_to_cm(5 + lengthBearing / 2.0 + length1 + lengthGear / 2.0), mm_to_cm(diameterBearing/2.0)), false);	 
	point[10] = skPoints->MethodAdd(p_TransGeom->MethodCreatePoint2d(mm_to_cm(5 + lengthBearing / 2.0 + length1 + length2+ lengthGear / 2.0), mm_to_cm(diameterBearing / 2.0)), false);
	point[11] = skPoints->MethodAdd(p_TransGeom->MethodCreatePoint2d(mm_to_cm(5 + lengthBearing / 2.0 + length1 + length2+ lengthGear / 2.0), mm_to_cm(diameterBearing / 4.0)), false);
	point[12] = skPoints->MethodAdd(p_TransGeom->MethodCreatePoint2d(mm_to_cm(5 + lengthBearing / 2.0 + length1 + length2+ lengthGear / 2.0+5), mm_to_cm(diameterBearing / 4.0)), false);
	point[13] = skPoints->MethodAdd(p_TransGeom->MethodCreatePoint2d(mm_to_cm(5 + lengthBearing / 2.0 + length1 + length2+ lengthGear / 2.0+5), 0), false);


	lines[0] = skLines->MethodAddByTwoPoints(point[0], point[1]);
	lines[1] = skLines->MethodAddByTwoPoints(point[1], point[2]);
	lines[2] = skLines->MethodAddByTwoPoints(point[2], point[3]);
	lines[3] = skLines->MethodAddByTwoPoints(point[3], point[4]);
	lines[4] = skLines->MethodAddByTwoPoints(point[4], point[5]);
	lines[5] = skLines->MethodAddByTwoPoints(point[5], point[6]);
	lines[6] = skLines->MethodAddByTwoPoints(point[6], point[7]);
	lines[7] = skLines->MethodAddByTwoPoints(point[7], point[8]);
	lines[8] = skLines->MethodAddByTwoPoints(point[8], point[9]);
	lines[9] = skLines->MethodAddByTwoPoints(point[9], point[10]);
	lines[10] = skLines->MethodAddByTwoPoints(point[10], point[11]);
	lines[11] = skLines->MethodAddByTwoPoints(point[11], point[12]);
	lines[12] = skLines->MethodAddByTwoPoints(point[12], point[13]);
	lines[13] = skLines->MethodAddByTwoPoints(point[13], point[0]);



	Profile *pProfile;
	skProfiles->raw__AddForSolid(&pProfile);

	RevolveFeatures *ftRevolve;
	p_partFeatures->get_RevolveFeatures(&ftRevolve); //указатель на коллекцию вращений в документе

	RevolveFeaturePtr revolve1 = ftRevolve->MethodAddFull(pProfile, p_workAxes->GetItem(1), kJoinOperation);  //вращаем сей чертёж


	FilletFeatures *pFilletFt;  //порождение сглаживаний
	p_partFeatures->get_FilletFeatures(&pFilletFt);

	EdgeCollection *edgeColl;
	p_invApp->TransientObjects->raw_CreateEdgeCollection(vtMissing, &edgeColl);

	SurfaceBody *SurfBody;
	SurfaceBodies *SurfBodies;

	p_PartComponentDef->get_SurfaceBodies(&SurfBodies);
	SurfBodies->get_Item(1, &SurfBody);

	Edges *edges;
	SurfBody->get_Edges(&edges);

	Edge *ed;
	edges->get_Item(1, &ed);
	edgeColl->MethodAdd(ed);
	edges->get_Item(3, &ed);
	edgeColl->MethodAdd(ed);
	edges->get_Item(5, &ed);
	edgeColl->MethodAdd(ed);
	edges->get_Item(6, &ed);
	edgeColl->MethodAdd(ed);
	edges->get_Item(8, &ed);
	edgeColl->MethodAdd(ed);
	edges->get_Item(10, &ed);
	edgeColl->MethodAdd(ed);
	edges->get_Item(12, &ed);
	edgeColl->MethodAdd(ed);

	FilletFeaturePtr fillFeat = pFilletFt->MethodAddSimple(edgeColl, 0.9f, false, false, false, false, false, false);

	PlanarSketch *pSketch2;
	p_plannarSketches->raw_Add(p_workPlanes->GetItem(2), false, &pSketch2);
	SketchPointPtr point2[6];
	SketchLinePtr lines2[2];
	SketchArcPtr arcs2[2];

	SketchPoints *skPoints2;
	SketchLines *skLines2;
	SketchArcs *skArcs;
	Profiles *skProfiles2;


	pSketch2->get_SketchPoints(&skPoints2);
	pSketch2->get_SketchLines(&skLines2);
	pSketch2->get_Profiles(&skProfiles2);
	pSketch2->get_SketchArcs(&skArcs);




	point2[0] = skPoints2->MethodAdd(p_TransGeom->MethodCreatePoint2d(-(5 + lengthBearing / 2.0 + length1 - wpz1), 0), false);
	point2[1] = skPoints2->MethodAdd(p_TransGeom->MethodCreatePoint2d(-(5 + lengthBearing / 2.0 + length1 - wpz1), dp), false);
	point2[2] = skPoints2->MethodAdd(p_TransGeom->MethodCreatePoint2d(-(5 + lengthBearing / 2.0 + length1 - wpz1), -(dp)), false);
	point2[3] = skPoints2->MethodAdd(p_TransGeom->MethodCreatePoint2d(-(5 + lengthBearing / 2.0 + length1 + wpz1), 0), false);
	point2[4] = skPoints2->MethodAdd(p_TransGeom->MethodCreatePoint2d(-(5 + lengthBearing / 2.0 + length1 + wpz1), dp), false);
	point2[5] = skPoints2->MethodAdd(p_TransGeom->MethodCreatePoint2d(-(5 + lengthBearing / 2.0 + length1 + wpz1), -(dp)), false);

	lines2[0] = skLines2->MethodAddByTwoPoints(point2[1], point2[4]);
	lines2[1] = skLines2->MethodAddByTwoPoints(point2[2], point2[5]);


	arcs2[0] = skArcs->MethodAddByCenterStartEndPoint(point2[0], point2[1], point2[2], false);    //порождение дуги через центр и 2 точки
	arcs2[1] = skArcs->MethodAddByCenterStartEndPoint(point2[3], point2[4], point2[5], true);

	Profile *pProfile2;
	skProfiles2->raw__AddForSolid(&pProfile2);

	ExtrudeFeatures *ftExtrude2;
	p_partFeatures->get_ExtrudeFeatures(&ftExtrude2);

	ExtrudeFeaturePtr extrude2 = ftExtrude2->MethodAddByDistanceExtent(pProfile2, (diameterGear / 2) + 2, kPositiveExtentDirection, kJoinOperation);   //выдавливание на пооолную высоту
	
	PlanarSketch *pSketch3;
	p_plannarSketches->raw_Add(p_workPlanes->GetItem(2), false, &pSketch3);
	SketchPointPtr point3[6];
	SketchLinePtr lines3[2];
	SketchArcPtr arcs3[2];

	SketchPoints *skPoints3;
	SketchLines *skLines3;
	SketchArcs *skArcs3;
	Profiles *skProfiles3;
	pSketch3->get_SketchPoints(&skPoints3);
	pSketch3->get_SketchLines(&skLines3);
	pSketch3->get_Profiles(&skProfiles3);
	pSketch3->get_SketchArcs(&skArcs3);




	point3[0] = skPoints3->MethodAdd(p_TransGeom->MethodCreatePoint2d(-(5/2.0 - wpz1), 0), false);
	point3[1] = skPoints3->MethodAdd(p_TransGeom->MethodCreatePoint2d(-(5 / 2.0 - wpz1), dp), false);   //pow-возведение в степень	
	point3[2] = skPoints3->MethodAdd(p_TransGeom->MethodCreatePoint2d(-(5 / 2.0 - wpz1), -(dp)), false);
	point3[3] = skPoints3->MethodAdd(p_TransGeom->MethodCreatePoint2d(-(5 / 2.0 + wpz1), 0), false);
	point3[4] = skPoints3->MethodAdd(p_TransGeom->MethodCreatePoint2d(-(5 / 2.0 + wpz1), dp), false);
	point3[5] = skPoints3->MethodAdd(p_TransGeom->MethodCreatePoint2d(-(5 / 2.0 + wpz1), -(dp)), false);

	lines3[0] = skLines3->MethodAddByTwoPoints(point3[1], point3[4]);
	lines3[1] = skLines3->MethodAddByTwoPoints(point3[2], point3[5]);


	arcs3[0] = skArcs3->MethodAddByCenterStartEndPoint(point3[0], point3[1], point3[2], false);    //порождение дуги через центр и 2 точки
	arcs3[1] = skArcs3->MethodAddByCenterStartEndPoint(point3[3], point3[4], point3[5], true);

	Profile *pProfile3;
	skProfiles3->raw__AddForSolid(&pProfile3);

	ExtrudeFeatures *ftExtrude3;
	p_partFeatures->get_ExtrudeFeatures(&ftExtrude3);

	ExtrudeFeaturePtr extrude3 = ftExtrude3->MethodAddByDistanceExtent(pProfile3, (diameterBearing/ 2) + 2, kPositiveExtentDirection, kJoinOperation);
	
	// Сохранение детали
	// TODO: Задавать пользовательский путь

	TCHAR szDirectory[MAX_PATH];
	::GetCurrentDirectory(sizeof(szDirectory) - 1, szDirectory);
	p_PartDocumnet->MethodSaveAs(szDirectory + _bstr_t("\\Сборка\\Вал.ipt"), false);

	return;
}