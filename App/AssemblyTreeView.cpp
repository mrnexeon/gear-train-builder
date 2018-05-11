// AssemblyTreeView.cpp: файл реализации
//

#include "stdafx.h"
#include "App.h"
#include "AssemblyTreeView.h"


// AssemblyTreeView

IMPLEMENT_DYNCREATE(AssemblyTreeView, CTreeView)

AssemblyTreeView::AssemblyTreeView()
{

}

AssemblyTreeView::~AssemblyTreeView()
{
}

BEGIN_MESSAGE_MAP(AssemblyTreeView, CTreeView)
END_MESSAGE_MAP()


// диагностика AssemblyTreeView

#ifdef _DEBUG
void AssemblyTreeView::AssertValid() const
{
	CTreeView::AssertValid();
}

#ifndef _WIN32_WCE
void AssemblyTreeView::Dump(CDumpContext& dc) const
{
	CTreeView::Dump(dc);
}
#endif
#endif //_DEBUG


// обработчики сообщений AssemblyTreeView
