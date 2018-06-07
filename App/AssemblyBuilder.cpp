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

	ComponentOccurrencePtr m_Component1;
	m_Component1 = p_ComponentDef->GetOccurrences()->MethodAdd(szDirectory + _bstr_t("\\Сборка\\Вал.ipt"), p_PosMatrix);

	ComponentOccurrencePtr m_Component2;
	m_Component2 = p_ComponentDef->GetOccurrences()->MethodAdd(szDirectory + _bstr_t("\\Сборка\\Шестерня.ipt"), p_PosMatrix);

	AssemblyComponentDefinitionPtr p_AssemCompDef;
	p_AssemCompDef = p_AssemblyDoc->GetComponentDefinition();

	FaceProxyPtr p_Face1;
	FaceProxyPtr p_Face2;

	m_Component1->MethodCreateGeometryProxy(m_Component1->SurfaceBodies->Item[1]->Faces->Item[21], (IDispatch**)&p_Face1);
	m_Component2->MethodCreateGeometryProxy(m_Component2->SurfaceBodies->Item[1]->Faces->Item[362], (IDispatch**)&p_Face2);

	p_AssemCompDef->Constraints->MethodAddMateConstraint(p_Face1, p_Face2, 0, kNoInference, kNoInference);

	//?

}