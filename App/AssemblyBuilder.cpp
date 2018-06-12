#include "stdafx.h"
#include "AssemblyBuilder.h"
#include "Inventor.h"
#include "Utility.h"

void BuildAssembly(double distance, CString folder) {
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

	LPCWSTR szDirectory;
	szDirectory = folder.GetString();

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

	ComponentOccurrencePtr p_Bearing1;
	p_Bearing1 = p_ComponentDef->GetOccurrences()->MethodAdd(szDirectory + _bstr_t("\\������\\���������1.ipt"), p_PosMatrix);

	ComponentOccurrencePtr p_Bearing2;
	p_Bearing2 = p_ComponentDef->GetOccurrences()->MethodAdd(szDirectory + _bstr_t("\\������\\���������1.ipt"), p_PosMatrix);

	ComponentOccurrencePtr p_Bearing3;
	p_Bearing3 = p_ComponentDef->GetOccurrences()->MethodAdd(szDirectory + _bstr_t("\\������\\���������2.ipt"), p_PosMatrix);

	ComponentOccurrencePtr p_Bearing4;
	p_Bearing4 = p_ComponentDef->GetOccurrences()->MethodAdd(szDirectory + _bstr_t("\\������\\���������2.ipt"), p_PosMatrix);
	
	// ������� ���
	WorkAxisProxyPtr p_WorkAxis1;
	WorkAxisProxyPtr p_WorkAxis2;

	// ������� ���������
	WorkPlaneProxyPtr p_WorkPlane1;
	WorkPlaneProxyPtr p_WorkPlane2;

	// ������� �����
	FaceProxyPtr p_Face1;
	FaceProxyPtr p_Face2;

	// ������
	PartComponentDefinitionPtr p_Shaft1Def = p_Shaft1->Definition;
	PartComponentDefinitionPtr p_Shaft2Def = p_Shaft2->Definition;
	PartComponentDefinitionPtr p_Gear1Def = p_Gear1->Definition;
	PartComponentDefinitionPtr p_Gear2Def = p_Gear2->Definition;
	PartComponentDefinitionPtr p_Bearing1Def = p_Bearing1->Definition;
	PartComponentDefinitionPtr p_Bearing2Def = p_Bearing2->Definition;
	PartComponentDefinitionPtr p_Bearing3Def = p_Bearing3->Definition;
	PartComponentDefinitionPtr p_Bearing4Def = p_Bearing4->Definition;

	// ��������� ��� �����
	p_Shaft1->MethodCreateGeometryProxy(p_Shaft1Def->WorkAxes->Item[1], (IDispatch**)&p_WorkAxis1);
	p_Shaft2->MethodCreateGeometryProxy(p_Shaft2Def->WorkAxes->Item[1], (IDispatch**)&p_WorkAxis2);
	p_AssemCompDef->Constraints->MethodAddMateConstraint(p_WorkAxis1, p_WorkAxis2, mm_to_cm(distance), kNoInference, kNoInference);

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

	// ��������� ��� ������� ���� � �����������
	p_Shaft1->MethodCreateGeometryProxy(p_Shaft1Def->WorkAxes->Item[1], (IDispatch**)&p_WorkAxis1);
	p_Bearing1->MethodCreateGeometryProxy(p_Bearing1Def->WorkAxes->Item[1], (IDispatch**)&p_WorkAxis2);
	p_AssemCompDef->Constraints->MethodAddMateConstraint(p_WorkAxis1, p_WorkAxis2, 0, kNoInference, kNoInference);

	p_Shaft1->MethodCreateGeometryProxy(p_Shaft1Def->WorkAxes->Item[1], (IDispatch**)&p_WorkAxis1);
	p_Bearing2->MethodCreateGeometryProxy(p_Bearing2Def->WorkAxes->Item[1], (IDispatch**)&p_WorkAxis2);
	p_AssemCompDef->Constraints->MethodAddMateConstraint(p_WorkAxis1, p_WorkAxis2, 0, kNoInference, kNoInference);

	// �������� ���������� �� ������ ���
	p_Shaft1->MethodCreateGeometryProxy(p_Shaft1Def->SurfaceBodies->Item[1]->Faces->Item[13], (IDispatch**)&p_Face1);
	p_Bearing1->MethodCreateGeometryProxy(p_Bearing1Def->SurfaceBodies->Item[1]->Faces->Item[5], (IDispatch**)&p_Face2);
	p_AssemCompDef->Constraints->MethodAddMateConstraint(p_Face1, p_Face2, 0, kNoInference, kNoInference);

	p_Shaft1->MethodCreateGeometryProxy(p_Shaft1Def->SurfaceBodies->Item[1]->Faces->Item[29], (IDispatch**)&p_Face1);
	p_Bearing2->MethodCreateGeometryProxy(p_Bearing2Def->SurfaceBodies->Item[1]->Faces->Item[1], (IDispatch**)&p_Face2);
	p_AssemCompDef->Constraints->MethodAddMateConstraint(p_Face1, p_Face2, 0, kNoInference, kNoInference);

	// ��������� ��� ������� ���� � �����������
	p_Shaft2->MethodCreateGeometryProxy(p_Shaft2Def->WorkAxes->Item[1], (IDispatch**)&p_WorkAxis1);
	p_Bearing3->MethodCreateGeometryProxy(p_Bearing3Def->WorkAxes->Item[1], (IDispatch**)&p_WorkAxis2);
	p_AssemCompDef->Constraints->MethodAddMateConstraint(p_WorkAxis1, p_WorkAxis2, 0, kNoInference, kNoInference);

	p_Shaft2->MethodCreateGeometryProxy(p_Shaft2Def->WorkAxes->Item[1], (IDispatch**)&p_WorkAxis1);
	p_Bearing4->MethodCreateGeometryProxy(p_Bearing4Def->WorkAxes->Item[1], (IDispatch**)&p_WorkAxis2);
	p_AssemCompDef->Constraints->MethodAddMateConstraint(p_WorkAxis1, p_WorkAxis2, 0, kNoInference, kNoInference);

	// �������� ���������� �� ������ ���
	p_Shaft2->MethodCreateGeometryProxy(p_Shaft2Def->SurfaceBodies->Item[1]->Faces->Item[13], (IDispatch**)&p_Face1);
	p_Bearing3->MethodCreateGeometryProxy(p_Bearing3Def->SurfaceBodies->Item[1]->Faces->Item[5], (IDispatch**)&p_Face2);
	p_AssemCompDef->Constraints->MethodAddMateConstraint(p_Face1, p_Face2, 0, kNoInference, kNoInference);

	p_Shaft2->MethodCreateGeometryProxy(p_Shaft2Def->SurfaceBodies->Item[1]->Faces->Item[29], (IDispatch**)&p_Face1);
	p_Bearing4->MethodCreateGeometryProxy(p_Bearing4Def->SurfaceBodies->Item[1]->Faces->Item[1], (IDispatch**)&p_Face2);
	p_AssemCompDef->Constraints->MethodAddMateConstraint(p_Face1, p_Face2, 0, kNoInference, kNoInference);
}