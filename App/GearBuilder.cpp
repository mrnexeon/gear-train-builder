#include "stdafx.h"
#include "Inventor.h"
#include "PartBuilders.h"

void BuildGear(double outerDiameter, double insideDiameter, unsigned cogCount) {
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

	p_PartDocumnet->DisplayName = _T("��������"); // �������� ������

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

	return;
}