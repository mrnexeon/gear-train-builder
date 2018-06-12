
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
	BuildGear(500.0, 100.0, 40.0, 32, 20.0, 5.0, 1);
	BuildGear(800.0, 200.0, 40.0, 36, 30.0, 10.0, 2);

}

void CAppView::On32772()
{
	InitializeInventor();
	BuildShaft(100.0, 125.0, 100.0, 80.0, 30.0, 20.0, 20.0,5.0, 1);
	BuildShaft(200.0, 250.0, 200.0, 100.0, 50.0, 20.0, 30.0, 10.0, 2);

}

void CAppView::On32773()
{
	InitializeInventor();
	BuildBearing(80.0,120.0, 20, 1);
	BuildBearing(100.0, 150.0, 26, 2);

}
void CAppView::Update()
{
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

	if (selected == 0)
	{
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
		GetDlgItem(IDC_STATIC7)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_EDIT7)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_STATIC7)->SetWindowTextW(_T("�����-�� �������"));
		GetDlgItem(IDC_STATIC8)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_EDIT8)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_STATIC8)->SetWindowTextW(_T("������ ����"));
		GetDlgItem(IDC_STATIC24)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_STATIC24)->SetWindowTextW(_T("������ ���"));
		GetDlgItem(IDC_STATIC25)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_STATIC25)->SetWindowTextW(_T("������ ���"));
		GetDlgItem(IDC_STATIC9)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_EDIT9)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_STATIC9)->SetWindowTextW(_T("�����-�� �������"));
		GetDlgItem(IDC_STATIC10)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_EDIT10)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_STATIC10)->SetWindowTextW(_T("������ ����"));
	}

}


void CAppView::On32774()
{
	InitializeInventor();
	BuildAssembly();
}
