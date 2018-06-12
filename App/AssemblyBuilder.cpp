#include "stdafx.h"
#include "AssemblyBuilder.h"
#include "Inventor.h"


void BuildAssembly() {
	// Указатель на менеджер по построению геометрии
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
	p_Shaft1 = p_ComponentDef->GetOccurrences()->MethodAdd(szDirectory + _bstr_t("\\Сборка\\Вал1.ipt"), p_PosMatrix);

	ComponentOccurrencePtr p_Gear1;
	p_Gear1 = p_ComponentDef->GetOccurrences()->MethodAdd(szDirectory + _bstr_t("\\Сборка\\Шестерня1.ipt"), p_PosMatrix);

	ComponentOccurrencePtr p_Shaft2;
	p_Shaft2 = p_ComponentDef->GetOccurrences()->MethodAdd(szDirectory + _bstr_t("\\Сборка\\Вал2.ipt"), p_PosMatrix);

	ComponentOccurrencePtr p_Gear2;
	p_Gear2 = p_ComponentDef->GetOccurrences()->MethodAdd(szDirectory + _bstr_t("\\Сборка\\Шестерня2.ipt"), p_PosMatrix);
	
	// Рабочие оси
	WorkAxisProxyPtr p_WorkAxis1;
	WorkAxisProxyPtr p_WorkAxis2;

	// Рабочие плоскости
	WorkPlaneProxyPtr p_WorkPlane1;
	WorkPlaneProxyPtr p_WorkPlane2;

	// Детали
	PartComponentDefinitionPtr p_Shaft1Def = p_Shaft1->Definition;
	PartComponentDefinitionPtr p_Shaft2Def = p_Shaft2->Definition;
	PartComponentDefinitionPtr p_Gear1Def = p_Gear1->Definition;
	PartComponentDefinitionPtr p_Gear2Def = p_Gear2->Definition;

	// Совмещаем Оси валов
	p_Shaft1->MethodCreateGeometryProxy(p_Shaft1Def->WorkAxes->Item[1], (IDispatch**)&p_WorkAxis1);
	p_Shaft2->MethodCreateGeometryProxy(p_Shaft2Def->WorkAxes->Item[1], (IDispatch**)&p_WorkAxis2);
	p_AssemCompDef->Constraints->MethodAddMateConstraint(p_WorkAxis1, p_WorkAxis2, 65.0, kNoInference, kNoInference);

	// Совмещаем Оси валов в одну плоскость

	p_Shaft1->MethodCreateGeometryProxy(p_Shaft1Def->WorkPlanes->Item[1], (IDispatch**)&p_WorkPlane1);
	p_Shaft2->MethodCreateGeometryProxy(p_Shaft2Def->WorkPlanes->Item[1], (IDispatch**)&p_WorkPlane2);
	p_AssemCompDef->Constraints->MethodAddMateConstraint(p_WorkPlane1, p_WorkPlane2, 0, kNoInference, kNoInference);

	p_Shaft1->MethodCreateGeometryProxy(p_Shaft1Def->WorkPlanes->Item[3], (IDispatch**)&p_WorkPlane1);
	p_Shaft2->MethodCreateGeometryProxy(p_Shaft2Def->WorkPlanes->Item[3], (IDispatch**)&p_WorkPlane2);
	p_AssemCompDef->Constraints->MethodAddMateConstraint(p_WorkPlane1, p_WorkPlane2, 0, kNoInference, kNoInference);

	// Совмещаем Оси первого вала и шестерни
	p_Gear1->MethodCreateGeometryProxy(p_Gear1Def->WorkAxes->Item[2], (IDispatch**)&p_WorkAxis1);
	p_Shaft1->MethodCreateGeometryProxy(p_Shaft1Def->WorkAxes->Item[1], (IDispatch**)&p_WorkAxis2);
	p_AssemCompDef->Constraints->MethodAddMateConstraint(p_WorkAxis1, p_WorkAxis2, 0, kNoInference, kNoInference);

	// Совмещаем Оси второго вала и шестерни
	p_Gear2->MethodCreateGeometryProxy(p_Gear2Def->WorkAxes->Item[2], (IDispatch**)&p_WorkAxis1);
	p_Shaft2->MethodCreateGeometryProxy(p_Shaft2Def->WorkAxes->Item[1], (IDispatch**)&p_WorkAxis2);
	p_AssemCompDef->Constraints->MethodAddMateConstraint(p_WorkAxis1, p_WorkAxis2, 0, kNoInference, kNoInference);

	// Центруем первую шестерню на вале
	p_Shaft1->MethodCreateGeometryProxy(p_Shaft1Def->WorkPlanes->Item[1], (IDispatch**)&p_WorkPlane1);
	p_Gear1->MethodCreateGeometryProxy(p_Gear1Def->WorkPlanes->Item[2], (IDispatch**)&p_WorkPlane2);
	p_AssemCompDef->Constraints->MethodAddMateConstraint(p_WorkPlane1, p_WorkPlane2, 0, kNoInference, kNoInference);

	// Центруем вторую шестерню на вале
	p_Shaft2->MethodCreateGeometryProxy(p_Shaft2Def->WorkPlanes->Item[1], (IDispatch**)&p_WorkPlane1);
	p_Gear2->MethodCreateGeometryProxy(p_Gear2Def->WorkPlanes->Item[2], (IDispatch**)&p_WorkPlane2);
	p_AssemCompDef->Constraints->MethodAddMateConstraint(p_WorkPlane1, p_WorkPlane2, 0, kNoInference, kNoInference);

	// Совмещаем шпонку и отверстие первого вала и шестерни соотвественно
	p_Shaft1->MethodCreateGeometryProxy(p_Shaft1Def->WorkAxes->Item[2], (IDispatch**)&p_WorkAxis1);
	p_Gear1->MethodCreateGeometryProxy(p_Gear1Def->WorkAxes->Item[3], (IDispatch**)&p_WorkAxis2);
	p_AssemCompDef->Constraints->MethodAddMateConstraint(p_WorkAxis1, p_WorkAxis2, 0, kNoInference, kNoInference);

	// Совмещаем шпонку и отверстие второго вала и шестерни соотвественно
	p_Shaft2->MethodCreateGeometryProxy(p_Shaft2Def->WorkAxes->Item[2], (IDispatch**)&p_WorkAxis1);
	p_Gear2->MethodCreateGeometryProxy(p_Gear2Def->WorkAxes->Item[3], (IDispatch**)&p_WorkAxis2);
	p_AssemCompDef->Constraints->MethodAddMateConstraint(p_WorkAxis1, p_WorkAxis2, 0, kNoInference, kNoInference);
}