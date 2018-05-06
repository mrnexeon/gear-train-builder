#include "stdafx.h"
#include "Inventor.h"
#include "PartBuilders.h"

void BuildGear(double outerDiameter, double insideDiameter, unsigned cogCount) {
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

	return;
}