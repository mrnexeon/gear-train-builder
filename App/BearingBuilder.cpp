#include "stdafx.h"
#include "Inventor.h"
#include "PartBuilders.h"
#include "Utility.h"

void BuildBearing(double indiametr, unsigned ballCount,double outdiametr, double Lcount ) {
	// ��������� �� ��������, �������������� ������
	PartDocumentPtr p_PartDocumnet;

	// ��������� �� ������ � �� ���������� (������, ��� � �.�.)
	PartComponentDefinition *p_PartComponentDef;

	// ��������� �� �������� �� ���������� ���������
	TransientGeometry *p_TransGeom;

	// ��������� �� �������� �� ���������� ������
	TransactionManagerPtr p_TransManager;

	// ������ ������������� ���� ������
	Transaction *p_Transaction;

	Document *Doc; // ���� ������� � Inventor
	PlanarSketches *p_plannarSketches; // ������
	WorkPlanes *p_workPlanes; // ������� ���������
	PartFeatures *p_partFeatures; // �����������
	WorkAxes *p_workAxes; // ���
	WorkPoints *p_workPoints; // �����

	p_PartDocumnet = p_invApp->Documents->MethodAdd( // �������� ������
		kPartDocumentObject,
		p_invApp->FileManager->MethodGetTemplateFile(
			kPartDocumentObject,
			kMetricSystemOfMeasure, // ����������� ��
			kGOST_DraftingStandard),
		true
	);

	p_PartDocumnet->DisplayName = _T("���������"); // �������� ������

	// ������������� ����������

	p_TransManager = p_invApp->GetTransactionManager();
	p_invApp->get_TransientGeometry(&p_TransGeom);
	Doc = CComQIPtr<Document>(p_PartDocumnet); 
	p_PartDocumnet->get_ComponentDefinition(&p_PartComponentDef);

	// ������������� ���������� �� ���������� ������

	p_PartComponentDef->get_Sketches(&p_plannarSketches);
	p_PartComponentDef->get_WorkPlanes(&p_workPlanes);
	p_PartComponentDef->get_Features(&p_partFeatures);
	p_PartComponentDef->get_WorkAxes(&p_workAxes);
	p_PartComponentDef->get_WorkPoints(&p_workPoints);

	p_TransManager->raw_StartTransaction(Doc, _T("���������"), &p_Transaction);

	/* TODO: ��������� ������ �� ����������, ��������� ������ � ����� ������ */

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

	SketchPointPtr points1[9];
	SketchPoints *p_Points;
	SketchLines *p_Lines;
	SketchArcs *p_Arc;

	p_sketch1->get_SketchPoints(&p_Points);
	p_sketch1->get_SketchLines(&p_Lines);
	p_sketch1->get_SketchArcs(&p_Arc);

	double DiametrofBall;
	DiametrofBall = (Lcount / 2 - 2);

	points1[0] = p_Points->MethodAdd(p_TransGeom->MethodCreatePoint2d(mm_to_cm(-DiametrofBall), mm_to_cm(indiametr / 2.0)), false);
	points1[1] = p_Points->MethodAdd(p_TransGeom->MethodCreatePoint2d(mm_to_cm(-DiametrofBall-2), mm_to_cm(indiametr / 2.0)), false);
	points1[2] = p_Points->MethodAdd(p_TransGeom->MethodCreatePoint2d(mm_to_cm(-DiametrofBall-2), mm_to_cm(outdiametr / 2.0)), false);
	points1[3] = p_Points->MethodAdd(p_TransGeom->MethodCreatePoint2d(mm_to_cm(DiametrofBall + 2), mm_to_cm(outdiametr / 2.0)), false);
	points1[4] = p_Points->MethodAdd(p_TransGeom->MethodCreatePoint2d(mm_to_cm(DiametrofBall + 2), mm_to_cm(indiametr / 2.0)), false);
	points1[5] = p_Points->MethodAdd(p_TransGeom->MethodCreatePoint2d(mm_to_cm(DiametrofBall), mm_to_cm(indiametr / 2.0)), false);
	points1[6] = p_Points->MethodAdd(p_TransGeom->MethodCreatePoint2d(0, mm_to_cm((indiametr-4) / 2.0)), false);
	points1[7] = p_Points->MethodAdd(p_TransGeom->MethodCreatePoint2d(mm_to_cm(-DiametrofBall - 2),0), false);
	points1[8] = p_Points->MethodAdd(p_TransGeom->MethodCreatePoint2d(mm_to_cm(DiametrofBall + 2), 0), false);
	

	p_Lines->MethodAddByTwoPoints(points1[0], points1[1]);
	p_Lines->MethodAddByTwoPoints(points1[1], points1[2]);
	p_Lines->MethodAddByTwoPoints(points1[2], points1[3]);
	p_Lines->MethodAddByTwoPoints(points1[3], points1[4]);
	p_Lines->MethodAddByTwoPoints(points1[4], points1[5]);
	p_Lines->MethodAddByTwoPoints(points1[7], points1[8]);

	p_Arc->MethodAddByCenterStartEndPoint(points1[6], points1[0], points1[5], false);

	

	return;
}