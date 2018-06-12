
// AppView.cpp: ���������� ������ CAppView
//

#include "stdafx.h"
// SHARED_HANDLERS ����� ���������� � ������������ �������� ��������� ���������� ������� ATL, �������
// � ������; ��������� ��������� ������������ ��� ��������� � ������ �������.
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
	// ����������� ������� ������
	ON_COMMAND(ID_FILE_PRINT, &CFormView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CFormView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CFormView::OnFilePrintPreview)
	ON_COMMAND(ID_32771, &CAppView::On32771)
	ON_COMMAND(ID_32772, &CAppView::On32772)
	ON_COMMAND(ID_32773, &CAppView::On32773)
	ON_COMMAND(ID_32774, &CAppView::On32774)
	ON_BN_CLICKED(IDC_BUTTON1, &CAppView::OnBnClickedButton1)
END_MESSAGE_MAP()

// �������� ��� ����������� CAppView

CAppView::CAppView()
	: CFormView(IDD_APP_FORM)
{
	// TODO: �������� ��� ��������

}

CAppView::~CAppView()
{
}

void CAppView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_STATIC100, _image);
	DDX_Text(pDX, IDC_EDIT1, _h);
	DDX_Text(pDX, IDC_EDIT2, _h);
	DDX_Text(pDX, IDC_EDIT3, _h);
	DDX_Text(pDX, IDC_EDIT4, _h);
	DDX_Text(pDX, IDC_EDIT14, _h);
	DDX_Text(pDX, IDC_EDIT15, _h);
	DDX_Text(pDX, IDC_EDIT16, _h);
	DDX_Text(pDX, IDC_EDIT17, _h);
	DDX_Text(pDX, IDC_EDIT5, _h);
	DDX_Text(pDX, IDC_EDIT6, _h);
	DDX_Text(pDX, IDC_EDIT20, _h);
	DDX_Text(pDX, IDC_EDIT21, _h);
	DDX_Text(pDX, IDC_EDIT7, _h);
	DDX_Text(pDX, IDC_EDIT8, _h);
	DDX_Text(pDX, IDC_EDIT9, _h);
	DDX_Text(pDX, IDC_EDIT10, _h);


}

BOOL CAppView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �������� ����� Window ��� ����� ����������� ���������
	//  CREATESTRUCT cs

	return CFormView::PreCreateWindow(cs);
}

void CAppView::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();
	
}


// ������ CAppView

BOOL CAppView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// ���������� �� ���������
	return DoPreparePrinting(pInfo);
}

void CAppView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �������� �������������� ������������� ����� �������
}

void CAppView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �������� ������� ����� ������
}

void CAppView::OnPrint(CDC* pDC, CPrintInfo* /*pInfo*/)
{
	// TODO: �������� ���� ��� ������
}


// ����������� CAppView

#ifdef _DEBUG
void CAppView::AssertValid() const
{
	CFormView::AssertValid();
}

void CAppView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CAppDoc* CAppView::GetDocument() const // �������� ������������ ������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CAppDoc)));
	return (CAppDoc*)m_pDocument;
}

#endif //_DEBUG

void CAppView::On32771()
{
	InitializeInventor();
	BuildGear(150.0, 100.0, 40.0, 32, 20.0, 5.0);
}


void CAppView::On32772()
{
	InitializeInventor();
	BuildShaft(100.0, 100.0, 100.0, 80.0, 30.0, 20.0);
}


void CAppView::On32773()
{
	InitializeInventor();
	BuildBearing(85.0, 23, 120.0, 20.0);
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
		GetDlgItem(IDC_STATIC18)->SetWindowTextW(_T("������"));
		GetDlgItem(IDC_STATIC13)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_STATIC13)->SetWindowTextW(_T("��������"));
		GetDlgItem(IDC_STATIC1)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_EDIT1)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_STATIC1)->SetWindowTextW(_T("������� �������"));
		GetDlgItem(IDC_STATIC2)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_EDIT2)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_STATIC2)->SetWindowTextW(_T("���������� �������"));
		GetDlgItem(IDC_STATIC3)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_EDIT3)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_STATIC3)->SetWindowTextW(_T("���������� ������"));
		GetDlgItem(IDC_STATIC4)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_EDIT4)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_STATIC4)->SetWindowTextW(_T("������ ��������"));
		GetDlgItem(IDC_STATIC14)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_EDIT14)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_STATIC14)->SetWindowTextW(_T("������� �������"));
		GetDlgItem(IDC_STATIC15)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_EDIT15)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_STATIC15)->SetWindowTextW(_T("���������� �������"));
		GetDlgItem(IDC_STATIC16)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_EDIT16)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_STATIC16)->SetWindowTextW(_T("���������� ������"));
		GetDlgItem(IDC_STATIC17)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_EDIT17)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_STATIC17)->SetWindowTextW(_T("������ ������"));
	}
	if (selected == 1)
	{
		CBitmap bm;
		bm.LoadBitmap(IDB_BITMAP2); _image.SetBitmap(bm);
		GetDlgItem(IDC_STATIC5)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_EDIT5)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_STATIC5)->SetWindowTextW(_T("���������� �������"));
		GetDlgItem(IDC_STATIC6)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_EDIT6)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_STATIC6)->SetWindowTextW(_T("������ ����������"));
		GetDlgItem(IDC_STATIC20)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_EDIT20)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_STATIC20)->SetWindowTextW(_T("���������� �������"));
		GetDlgItem(IDC_STATIC21)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_EDIT21)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_STATIC21)->SetWindowTextW(_T("������ ����������"));
		GetDlgItem(IDC_STATIC22)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_STATIC22)->SetWindowTextW(_T("������ ���������"));
		GetDlgItem(IDC_STATIC23)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_STATIC23)->SetWindowTextW(_T("������ ���������"));
	}

	if (selected == 2)
	{
		CBitmap bm;
		bm.LoadBitmap(IDB_BITMAP3); _image.SetBitmap(bm);
		GetDlgItem(IDC_STATIC7)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_EDIT7)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_STATIC7)->SetWindowTextW(_T("����� ���� l1"));
		GetDlgItem(IDC_STATIC8)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_EDIT8)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_STATIC8)->SetWindowTextW(_T("����� ���� l2"));
		GetDlgItem(IDC_STATIC24)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_STATIC24)->SetWindowTextW(_T("������ ���"));
		GetDlgItem(IDC_STATIC25)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_STATIC25)->SetWindowTextW(_T("������ ���"));
		GetDlgItem(IDC_STATIC9)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_EDIT9)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_STATIC9)->SetWindowTextW(_T("����� ���� l1"));
		GetDlgItem(IDC_STATIC10)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_EDIT10)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_STATIC10)->SetWindowTextW(_T("����� ���� l2"));
	}
	
}


void CAppView::On32774()
{
	InitializeInventor();
	BuildAssembly();
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


}
