
// AppView.cpp: реализация класса CAppView
//

#include "stdafx.h"
// SHARED_HANDLERS можно определить в обработчиках фильтров просмотра реализации проекта ATL, эскизов
// и поиска; позволяет совместно использовать код документа в данным проекте.
#ifndef SHARED_HANDLERS
#include "App.h"
#endif

#include "MainFrm.h"

#include "PartBuilders.h"
#include "AssemblyBuilder.h"
#include "Inventor.h"

#include "AppDoc.h"
#include "AppView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAppView

IMPLEMENT_DYNCREATE(CAppView, CFormView)

BEGIN_MESSAGE_MAP(CAppView, CFormView)
	// Стандартные команды печати
	ON_COMMAND(ID_FILE_PRINT, &CFormView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CFormView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CFormView::OnFilePrintPreview)
	ON_COMMAND(ID_32771, &CAppView::On32771)
	ON_COMMAND(ID_32772, &CAppView::On32772)
	ON_COMMAND(ID_32773, &CAppView::On32773)
	ON_COMMAND(ID_32774, &CAppView::On32774)
	ON_BN_CLICKED(IDC_BUTTON1, &CAppView::OnBnClickedButton1)
END_MESSAGE_MAP()

// Создание или уничтожение CAppView

CAppView::CAppView()
	: CFormView(IDD_APP_FORM)
{
	// TODO: добавьте код создания

}

CAppView::~CAppView()
{
}

void CAppView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_STATIC100, _image);
	DDX_Text(pDX, IDC_EDIT1, m_DiametrVnechShest);
	DDX_Text(pDX, IDC_EDIT2, m_DiametrVnytrShest);
	DDX_Text(pDX, IDC_EDIT3, m_nZyb);
	DDX_Text(pDX, IDC_EDIT4, m_ShirinaShest);
	DDX_Text(pDX, IDC_EDIT15, m_DiametrVnechShest2);
	DDX_Text(pDX, IDC_EDIT14, m_DiametrVnytrShest2);
	DDX_Text(pDX, IDC_EDIT16, m_nZyb2);
	DDX_Text(pDX, IDC_EDIT17, m_ShirinaShest2);
	DDX_Text(pDX, IDC_EDIT5, m_DiametrVnytrPodship);
	DDX_Text(pDX, IDC_EDIT6, m_nPoship);
	DDX_Text(pDX, IDC_EDIT20, m_DiametrVnytrPodship2);
	DDX_Text(pDX, IDC_EDIT21, m_nPoship2);
	DDX_Text(pDX, IDC_EDIT7, m_DlinaVala1);
	DDX_Text(pDX, IDC_EDIT8, m_DlinaVala2);
	DDX_Text(pDX, IDC_EDIT9, m_DlinaVala12);
	DDX_Text(pDX, IDC_EDIT10, m_DlinaVala22);
	DDX_Text(pDX, IDC_EDIT11, m_DiametrVnechPodship);
	DDX_Text(pDX, IDC_EDIT12, m_DiametrVnechPodship2);


}

BOOL CAppView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: изменить класс Window или стили посредством изменения
	//  CREATESTRUCT cs

	return CFormView::PreCreateWindow(cs);
}

void CAppView::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();
	
}


// Печать CAppView

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

void CAppView::OnPrint(CDC* pDC, CPrintInfo* /*pInfo*/)
{
	// TODO: добавьте свой код печати
}


// Диагностика CAppView

#ifdef _DEBUG
void CAppView::AssertValid() const
{
	CFormView::AssertValid();
}

void CAppView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CAppDoc* CAppView::GetDocument() const // встроена неотлаженная версия
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CAppDoc)));
	return (CAppDoc*)m_pDocument;
}

#endif //_DEBUG

void CAppView::On32771()
{
	InitializeInventor();
	BuildGear(500.0, 100.0, 40.0, 32, 20.0, 5.0, 1, NULL);
	BuildGear(800.0, 200.0, 40.0, 36, 30.0, 10.0, 2, NULL);

}

void CAppView::On32772()
{
	InitializeInventor();

	BuildShaft(100.0, 125.0, 100.0, 80.0, 30.0, 20.0, 20.0,5.0, 1, NULL);
	BuildShaft(200.0, 250.0, 200.0, 100.0, 50.0, 20.0, 30.0, 10.0, 2, NULL);
}

void CAppView::On32773()
{

	InitializeInventor();
	BuildBearing(80.0,120.0, 20, 1, NULL);
	BuildBearing(100.0, 150.0, 26, 2, NULL);

}
void CAppView::Update()
{
	UpdateData(true); {
	}
	
	int selected = ((CMainFrame*)AfxGetMainWnd())->m_pTreeView->m_iSelected;
	/*CString str;
	str.Format(_T("%i"), selected);*/

	//AfxMessageBox(str);
	GetDlgItem(IDC_STATIC1)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_STATIC2)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_STATIC3)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_STATIC4)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_STATIC5)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_STATIC6)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_STATIC7)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_STATIC8)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_STATIC18)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_STATIC13)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_STATIC1)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_STATIC2)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_STATIC3)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_STATIC4)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_STATIC14)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_STATIC15)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_STATIC16)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_STATIC17)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_STATIC20)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_STATIC21)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_STATIC22)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_STATIC23)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_STATIC24)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_STATIC25)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_STATIC9)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_STATIC10)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_STATIC11)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_STATIC12)->ShowWindow(SW_HIDE);
	

	
	GetDlgItem(IDC_BUTTON1)->ShowWindow(SW_HIDE);


	GetDlgItem(IDC_EDIT1)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_EDIT2)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_EDIT3)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_EDIT4)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_EDIT5)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_EDIT6)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_EDIT7)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_EDIT8)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_EDIT1)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_EDIT2)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_EDIT3)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_EDIT14)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_EDIT15)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_EDIT16)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_EDIT17)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_EDIT20)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_EDIT21)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_EDIT9)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_EDIT10)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_EDIT11)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_EDIT12)->ShowWindow(SW_HIDE);
	

	if (selected == -1) {
		CBitmap bm;
		bm.LoadBitmap(IDB_BITMAP4); _image.SetBitmap(bm);
		GetDlgItem(IDC_BUTTON1)->ShowWindow(SW_SHOW);
	}

	if (selected == 0)
	{
		CBitmap bm; 
		bm.LoadBitmap(IDB_BITMAP1); _image.SetBitmap(bm);
		GetDlgItem(IDC_STATIC18)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_STATIC18)->SetWindowTextW(_T("Колесо"));
		GetDlgItem(IDC_STATIC13)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_STATIC13)->SetWindowTextW(_T("Шестерня"));
		GetDlgItem(IDC_STATIC1)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_EDIT1)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_STATIC1)->SetWindowTextW(_T("Внешний диаметр"));
		GetDlgItem(IDC_STATIC2)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_EDIT2)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_STATIC2)->SetWindowTextW(_T("Внутренний диаметр"));
		GetDlgItem(IDC_STATIC3)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_EDIT3)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_STATIC3)->SetWindowTextW(_T("Количество зубьев"));
		GetDlgItem(IDC_STATIC4)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_EDIT4)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_STATIC4)->SetWindowTextW(_T("Ширина шестерни"));
		GetDlgItem(IDC_STATIC14)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_EDIT14)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_STATIC14)->SetWindowTextW(_T("Внешний диаметр"));
		GetDlgItem(IDC_STATIC15)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_EDIT15)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_STATIC15)->SetWindowTextW(_T("Внутренний диаметр"));
		GetDlgItem(IDC_STATIC16)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_EDIT16)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_STATIC16)->SetWindowTextW(_T("Количество зубьев"));
		GetDlgItem(IDC_STATIC17)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_EDIT17)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_STATIC17)->SetWindowTextW(_T("Ширина колеса"));
	}
	if (selected == 1)
	{
		CBitmap bm;
		bm.LoadBitmap(IDB_BITMAP2); _image.SetBitmap(bm);
		GetDlgItem(IDC_STATIC5)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_EDIT5)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_STATIC5)->SetWindowTextW(_T("Внутренний диаметр"));
		GetDlgItem(IDC_STATIC11)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_EDIT11)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_STATIC11)->SetWindowTextW(_T("Внешний диаметр"));
		GetDlgItem(IDC_STATIC6)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_EDIT6)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_STATIC6)->SetWindowTextW(_T("Ширина подшипника"));
		GetDlgItem(IDC_STATIC20)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_EDIT20)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_STATIC20)->SetWindowTextW(_T("Внутренний диаметр"));
		GetDlgItem(IDC_STATIC12)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_EDIT12)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_STATIC12)->SetWindowTextW(_T("Внешний диаметр"));
		GetDlgItem(IDC_STATIC21)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_EDIT21)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_STATIC21)->SetWindowTextW(_T("Ширина подшипника"));
		GetDlgItem(IDC_STATIC22)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_STATIC22)->SetWindowTextW(_T("Первый подшипник"));
		GetDlgItem(IDC_STATIC23)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_STATIC23)->SetWindowTextW(_T("Второй подшипник"));
	}

	if (selected == 2)
	{
		CBitmap bm;
		bm.LoadBitmap(IDB_BITMAP3); _image.SetBitmap(bm);
		GetDlgItem(IDC_STATIC7)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_EDIT7)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_STATIC7)->SetWindowTextW(_T("Длина вала l1"));
		GetDlgItem(IDC_STATIC8)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_EDIT8)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_STATIC8)->SetWindowTextW(_T("Длина вала l2"));
		GetDlgItem(IDC_STATIC24)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_STATIC24)->SetWindowTextW(_T("Второй вал"));
		GetDlgItem(IDC_STATIC25)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_STATIC25)->SetWindowTextW(_T("Первый вал"));
		GetDlgItem(IDC_STATIC9)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_EDIT9)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_STATIC9)->SetWindowTextW(_T("Длина вала l1"));
		GetDlgItem(IDC_STATIC10)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_EDIT10)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_STATIC10)->SetWindowTextW(_T("Длина вала l2"));
	}
	
}


void CAppView::On32774()
{
	//InitializeInventor();
	//BuildAssembly();
}

// callback function 
INT CALLBACK BrowseCallbackProc(HWND hwnd, UINT uMsg, LPARAM lp, LPARAM pData)
{
	if (uMsg == BFFM_INITIALIZED) SendMessage(hwnd, BFFM_SETSELECTION, TRUE, pData);
	return 0;
}

// browseforfolder function
// returns the folder or an empty string if no folder was selected
// hwnd = handle to parent window
// title = text in dialog
// folder = selected (default) folder
CString BrowseForFolder(HWND hwnd, CString title, CString folder)
{
	CString ret;

	BROWSEINFO br;
	ZeroMemory(&br, sizeof(BROWSEINFO));
	br.lpfn = BrowseCallbackProc;
	br.ulFlags = BIF_RETURNONLYFSDIRS | BIF_NEWDIALOGSTYLE;
	br.hwndOwner = hwnd;
	br.lpszTitle = title;
	br.lParam = (LPARAM)folder.GetString();

	LPITEMIDLIST pidl = NULL;
	if ((pidl = SHBrowseForFolder(&br)) != NULL)
	{
		wchar_t buffer[MAX_PATH];
		if (SHGetPathFromIDList(pidl, buffer)) ret = buffer;
	}

	return ret;
}

void CAppView::OnBnClickedButton1()
{
	UpdateData(true);
	CString folder = BrowseForFolder(this->m_hWnd, L"Select Folder", L"C:\\");

	InitializeInventor();

	BuildGear(m_DiametrVnechShest, m_DiametrVnytrShest, m_ShirinaShest, m_nZyb, 20.0, 5.0, 1, folder);
	BuildGear(m_DiametrVnechShest2, m_DiametrVnytrShest2, m_ShirinaShest2, m_nZyb2, 30.0, 10.0, 2, folder);

	BuildShaft(m_DlinaVala1, m_DlinaVala2, m_DiametrVnytrShest, m_DiametrVnytrPodship, m_ShirinaShest, m_nPoship, 30.0, 5.0, 1, folder);
	BuildShaft(m_DlinaVala12, m_DlinaVala22, m_DiametrVnytrShest2, m_DiametrVnytrPodship2, m_ShirinaShest2, m_nPoship2, 50.0, 10.0, 2, folder);

	BuildBearing(m_DiametrVnytrPodship, m_DiametrVnechPodship, m_nPoship, 1, folder);
	BuildBearing(m_DiametrVnytrPodship2, m_DiametrVnechPodship2, m_nPoship2, 2, folder);

	BuildAssembly((m_DiametrVnechShest + m_DiametrVnechShest2) / 2.0, folder);
}
