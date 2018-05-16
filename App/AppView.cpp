// AppView.cpp: реализация класса CAppView
//

#include "stdafx.h"
// SHARED_HANDLERS можно определить в обработчиках фильтров просмотра реализации проекта ATL, эскизов
// и поиска; позволяет совместно использовать код документа в данным проекте.
#ifndef SHARED_HANDLERS
#include "App.h"
#endif

#include "AppDoc.h"
#include "AppView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

#include "Inventor.h"
#include "PartBuilders.h"

// CAppView

IMPLEMENT_DYNCREATE(CAppView, CView)

BEGIN_MESSAGE_MAP(CAppView, CView)
	// Стандартные команды печати
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CAppView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_COMMAND(ID_32772, &CAppView::OnBuildGearRequest)
	ON_COMMAND(ID_32773, &CAppView::OnBuildShaftRequest)
	ON_COMMAND(ID_32774, &CAppView::OnBuildBearingRequest)
END_MESSAGE_MAP()

// Создание или уничтожение CAppView

CAppView::CAppView()
{
	// TODO: добавьте код создания

}

CAppView::~CAppView()
{
}

BOOL CAppView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: изменить класс Window или стили посредством изменения
	//  CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// Рисование CAppView

void CAppView::OnDraw(CDC* /*pDC*/)
{
	CAppDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: добавьте здесь код отрисовки для собственных данных
}


// Печать CAppView


void CAppView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CAppView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// подготовка по умолчанию
	return DoPreparePrinting(pInfo);
}

void CAppView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: добавьте дополнительную инициализацию перед печатью
}

void CAppView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: добавьте очистку после печати
}

void CAppView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CAppView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// Диагностика CAppView

#ifdef _DEBUG
void CAppView::AssertValid() const
{
	CView::AssertValid();
}

void CAppView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CAppDoc* CAppView::GetDocument() const // встроена неотлаженная версия
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CAppDoc)));
	return (CAppDoc*)m_pDocument;
}
#endif //_DEBUG


// Обработчики сообщений CAppView


void CAppView::OnBuildGearRequest()
{
	InitializeInventor();
	BuildGear(400.0, 100.0, 40.0, 32, 30.0, 10.0);
}


void CAppView::OnBuildShaftRequest()
{
	InitializeInventor();
	BuildShaft(100.0, 100.0);
}


void CAppView::OnBuildBearingRequest()
{
	InitializeInventor();
	BuildBearing(100.0, 48);
}
