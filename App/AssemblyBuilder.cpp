#include "stdafx.h"
#include "AssemblyBuilder.h"
#include "Inventor.h"


void BuildAssembly() {
	// ��������� �� �������� �� ���������� ���������
	TransientGeometry *p_TransGeom;

	p_invApp->get_TransientGeometry(&p_TransGeom);

	// 
	AssemblyDocumentPtr p_AssemblyDoc;

	p_AssemblyDoc = p_invApp->Documents->MethodAdd(kAssemblyDocumentObject, 
	p_invApp->FileManager->MethodGetTemplateFile(
		kAssemblyDocumentObject,
		kMetricSystemOfMeasure,
		kGOST_DraftingStandard)
	, true);

	ComponentDefinitionPtr p_ComponentDef;
	p_ComponentDef = p_AssemblyDoc->GetComponentDefinition();

	MatrixPtr p_PosMatrix;
	p_PosMatrix = p_TransGeom->MethodCreateMatrix();

	TCHAR szDirectory[MAX_PATH];
	::GetCurrentDirectory(sizeof(szDirectory) - 1, szDirectory);

	AssemblyComponentDefinitionPtr p_AssemCompDef;
	p_AssemCompDef = p_AssemblyDoc->GetComponentDefinition();

	ComponentOccurrencePtr p_Shaft1;
	p_Shaft1 = p_ComponentDef->GetOccurrences()->MethodAdd(szDirectory + _bstr_t("\\������\\���1.ipt"), p_PosMatrix);

	ComponentOccurrencePtr p_Gear1;
	p_Gear1 = p_ComponentDef->GetOccurrences()->MethodAdd(szDirectory + _bstr_t("\\������\\��������1.ipt"), p_PosMatrix);

	ComponentOccurrencePtr p_Shaft2;
	p_Shaft2 = p_ComponentDef->GetOccurrences()->MethodAdd(szDirectory + _bstr_t("\\������\\���2.ipt"), p_PosMatrix);

	ComponentOccurrencePtr p_Gear2;
	p_Gear2 = p_ComponentDef->GetOccurrences()->MethodAdd(szDirectory + _bstr_t("\\������\\��������2.ipt"), p_PosMatrix);
	
	// ������� ���
	WorkAxisProxyPtr p_WorkAxis1;
	WorkAxisProxyPtr p_WorkAxis2;

	// ������� ���������
	WorkPlaneProxyPtr p_WorkPlane1;
	WorkPlaneProxyPtr p_WorkPlane2;

	// ������
	PartComponentDefinitionPtr p_Shaft1Def = p_Shaft1->Definition;
	PartComponentDefinitionPtr p_Shaft2Def = p_Shaft2->Definition;
	PartComponentDefinitionPtr p_Gear1Def = p_Gear1->Definition;
	PartComponentDefinitionPtr p_Gear2Def = p_Gear2->Definition;

	// ��������� ��� �����
	p_Shaft1->MethodCreateGeometryProxy(p_Shaft1Def->WorkAxes->Item[1], (IDispatch**)&p_WorkAxis1);
	p_Shaft2->MethodCreateGeometryProxy(p_Shaft2Def->WorkAxes->Item[1], (IDispatch**)&p_WorkAxis2);
	p_AssemCompDef->Constraints->MethodAddMateConstraint(p_WorkAxis1, p_WorkAxis2, 65.0, kNoInference, kNoInference);

	// ��������� ��� ����� � ���� ���������

	p_Shaft1->MethodCreateGeometryProxy(p_Shaft1Def->WorkPlanes->Item[1], (IDispatch**)&p_WorkPlane1);
	p_Shaft2->MethodCreateGeometryProxy(p_Shaft2Def->WorkPlanes->Item[1], (IDispatch**)&p_WorkPlane2);
	p_AssemCompDef->Constraints->MethodAddMateConstraint(p_WorkPlane1, p_WorkPlane2, 0, kNoInference, kNoInference);

	p_Shaft1->MethodCreateGeometryProxy(p_Shaft1Def->WorkPlanes->Item[3], (IDispatch**)&p_WorkPlane1);
	p_Shaft2->MethodCreateGeometryProxy(p_Shaft2Def->WorkPlanes->Item[3], (IDispatch**)&p_WorkPlane2);
	p_AssemCompDef->Constraints->MethodAddMateConstraint(p_WorkPlane1, p_WorkPlane2, 0, kNoInference, kNoInference);

	// ��������� ��� ������� ���� � ��������
	p_Gear1->MethodCreateGeometryProxy(p_Gear1Def->WorkAxes->Item[2], (IDispatch**)&p_WorkAxis1);
	p_Shaft1->MethodCreateGeometryProxy(p_Shaft1Def->WorkAxes->Item[1], (IDispatch**)&p_WorkAxis2);
	p_AssemCompDef->Constraints->MethodAddMateConstraint(p_WorkAxis1, p_WorkAxis2, 0, kNoInference, kNoInference);

	// ��������� ��� ������� ���� � ��������
	p_Gear2->MethodCreateGeometryProxy(p_Gear2Def->WorkAxes->Item[2], (IDispatch**)&p_WorkAxis1);
	p_Shaft2->MethodCreateGeometryProxy(p_Shaft2Def->WorkAxes->Item[1], (IDispatch**)&p_WorkAxis2);
	p_AssemCompDef->Constraints->MethodAddMateConstraint(p_WorkAxis1, p_WorkAxis2, 0, kNoInference, kNoInference);

	// �������� ������ �������� �� ����
	p_Shaft1->MethodCreateGeometryProxy(p_Shaft1Def->WorkPlanes->Item[1], (IDispatch**)&p_WorkPlane1);
	p_Gear1->MethodCreateGeometryProxy(p_Gear1Def->WorkPlanes->Item[2], (IDispatch**)&p_WorkPlane2);
	p_AssemCompDef->Constraints->MethodAddMateConstraint(p_WorkPlane1, p_WorkPlane2, 0, kNoInference, kNoInference);

	// �������� ������ �������� �� ����
	p_Shaft2->MethodCreateGeometryProxy(p_Shaft2Def->WorkPlanes->Item[1], (IDispatch**)&p_WorkPlane1);
	p_Gear2->MethodCreateGeometryProxy(p_Gear2Def->WorkPlanes->Item[2], (IDispatch**)&p_WorkPlane2);
	p_AssemCompDef->Constraints->MethodAddMateConstraint(p_WorkPlane1, p_WorkPlane2, 0, kNoInference, kNoInference);

	// ��������� ������ � ��������� ������� ���� � �������� �������������
	p_Shaft1->MethodCreateGeometryProxy(p_Shaft1Def->WorkAxes->Item[2], (IDispatch**)&p_WorkAxis1);
	p_Gear1->MethodCreateGeometryProxy(p_Gear1Def->WorkAxes->Item[3], (IDispatch**)&p_WorkAxis2);
	p_AssemCompDef->Constraints->MethodAddMateConstraint(p_WorkAxis1, p_WorkAxis2, 0, kNoInference, kNoInference);

	// ��������� ������ � ��������� ������� ���� � �������� �������������
	p_Shaft2->MethodCreateGeometryProxy(p_Shaft2Def->WorkAxes->Item[2], (IDispatch**)&p_WorkAxis1);
	p_Gear2->MethodCreateGeometryProxy(p_Gear2Def->WorkAxes->Item[3], (IDispatch**)&p_WorkAxis2);
	p_AssemCompDef->Constraints->MethodAddMateConstraint(p_WorkAxis1, p_WorkAxis2, 0, kNoInference, kNoInference);
}