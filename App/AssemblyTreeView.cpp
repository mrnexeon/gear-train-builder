// AssemblyTreeView.cpp: файл реализации
//

#include "stdafx.h"
#include "App.h"
#include "AssemblyTreeView.h"
#include "MainFrm.h"


// AssemblyTreeView

IMPLEMENT_DYNCREATE(CAssemblyTreeView, CTreeView)

CAssemblyTreeView::CAssemblyTreeView()
{
	m_ComponentNames.RemoveAll();
	//m_ComponentNames.Add(L"Сборка");
	m_ComponentNames.Add(L"Зубчатая передача");
	m_ComponentNames.Add(L"Подшипник");
	m_ComponentNames.Add(L"Вал");
	
}

CAssemblyTreeView::~CAssemblyTreeView()
{
}

BEGIN_MESSAGE_MAP(CAssemblyTreeView, CTreeView)
	ON_WM_CREATE()
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()


// диагностика AssemblyTreeView

#ifdef _DEBUG
void CAssemblyTreeView::AssertValid() const
{
	CTreeView::AssertValid();
}

#ifndef _WIN32_WCE
void CAssemblyTreeView::Dump(CDumpContext& dc) const
{
	CTreeView::Dump(dc);
}
#endif
#endif //_DEBUG


// обработчики сообщений AssemblyTreeView
void CAssemblyTreeView::FillTree()
{
	CTreeCtrl& ctlTree = (CTreeCtrl&)GetTreeCtrl();

	ctlTree.DeleteAllItems();
	m_hRoot = ctlTree.InsertItem(L"Сборка", -1, -1, NULL, TVI_FIRST);
	ctlTree.SetItemData(m_hRoot, -1);
	if (m_iSelected == -1)
		ctlTree.SetItemState(m_hRoot, TVIS_BOLD, TVIS_BOLD);

	HTREEITEM item;

	for (int i = 0; i < m_ComponentNames.GetSize(); i++)
	{
		item = ctlTree.InsertItem(m_ComponentNames[i], -1, -1, m_hRoot, TVI_LAST);
		ctlTree.SetItemData(item, i);
		if (i == m_iSelected)
			ctlTree.SetItemState(item, TVIS_BOLD, TVIS_BOLD);
		else
			ctlTree.SetItemState(item, 0, TVIS_BOLD);

	}

	ctlTree.Expand(m_hRoot, TVE_EXPAND);

	CWnd *pw = AfxGetMainWnd();
	if (pw)
	{
		((CMainFrame*)pw)->m_pMainView->Update();
	}

	//ctlTree.Expand(m_hRoot, TVE_EXPAND);

	/*m_hRoot = ctlTree.InsertItem(L"Сборка", -1, -1, NULL, TVI_FIRST);
	ctlTree.SetItemData(m_hRoot, 0);

	m_hComponent1 = ctlTree.InsertItem(L"Компонент1", m_hRoot, TVI_LAST);
	ctlTree.SetItemData(m_hComponent1, 1);

	m_hComponent2 = ctlTree.InsertItem(L"Компонент2", m_hRoot, TVI_LAST);
	ctlTree.SetItemData(m_hComponent2, 2);

	m_hComponent3 = ctlTree.InsertItem(L"Компонент3", m_hRoot, TVI_LAST);
	ctlTree.SetItemData(m_hComponent3, 3);*/





}

int CAssemblyTreeView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{

	lpCreateStruct->style |= TVS_HASLINES | TVS_HASBUTTONS | TVS_LINESATROOT | TVS_SHOWSELALWAYS;

	if (CTreeView::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  Добавьте специализированный код создания

	CTreeCtrl& ctlTree = (CTreeCtrl&)GetTreeCtrl();

	FillTree();




	return 0;
}


void CAssemblyTreeView::OnLButtonDown(UINT nFlags, CPoint point)
{
	CTreeView::OnLButtonDown(nFlags, point);
	// TODO: добавьте свой код обработчика сообщений или вызов стандартного
	CTreeCtrl& ctlTree = (CTreeCtrl&)GetTreeCtrl();

	HTREEITEM hItem = ctlTree.GetSelectedItem();
	if (hItem)
	{
		m_iSelected = ctlTree.GetItemData(hItem);



		FillTree();

		//ctlTree.SetItemState(hItem, TVIS_BOLD, TVIS_BOLD);


	}




}