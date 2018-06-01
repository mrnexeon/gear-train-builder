#pragma once
#include "afxcview.h"
class CAssemblyTreeView : public CTreeView
{
	DECLARE_DYNCREATE(CAssemblyTreeView)

protected:

	CAssemblyTreeView();           // ���������� �����������, ������������ ��� ������������ ��������
	virtual ~CAssemblyTreeView();

public:

	HTREEITEM m_hRoot;
	/*
	HTREEITEM m_hComponent1;
	HTREEITEM m_hComponent2;
	HTREEITEM m_hComponent3;*/

	//CArray <HTREEITEM, HTREEITEM> m_Items;

	int m_iSelected = -1;
	CStringArray m_ComponentNames;

#ifdef _DEBUG
	virtual void AssertValid() const;
#ifndef _WIN32_WCE
	virtual void Dump(CDumpContext& dc) const;
#endif
#endif

protected:
	DECLARE_MESSAGE_MAP()
public:
	void CAssemblyTreeView::FillTree();
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
};

