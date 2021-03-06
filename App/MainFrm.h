
// MainFrm.h: интерфейс класса CMainFrame
//

#pragma once
#include "AssemblyTreeView.h"
#include "AppDlg.h"
#include "AppView.h"

class CMainFrame : public CFrameWnd
{
	
protected: // создать только из сериализации
	CMainFrame();
	DECLARE_DYNCREATE(CMainFrame)

// Атрибуты
public:
	CAssemblyTreeView* m_pTreeView;
	CAppDlg *m_pAppDlg;
	CAppView *m_pMainView;

// Операции
public:

// Переопределение
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);

// Реализация
public:
	virtual ~CMainFrame();
	CSplitterWnd      m_wndSplitter;
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:  // встроенные члены панели элементов управления
	CToolBar          m_wndToolBar;
	CStatusBar        m_wndStatusBar;

// Созданные функции схемы сообщений
protected:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	DECLARE_MESSAGE_MAP()

	virtual BOOL OnCreateClient(LPCREATESTRUCT lpcs, CCreateContext* pContext);
};


