// AppDlg.cpp: ���� ����������
//

#include "stdafx.h"
#include "App.h"
#include "AppDlg.h"
#include "afxdialogex.h"
#include "AppDoc.h"
#include "MainFrm.h"

// ���������� ���� CAppDlg

IMPLEMENT_DYNAMIC(CAppDlg, CDialog)

CAppDlg::CAppDlg(CWnd* pParent /*=NULL*/)
	: CDialog(IDD_APP_FORM, pParent)
{

}

CAppDlg::~CAppDlg()
{
}

void CAppDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CAppDlg, CDialog)
END_MESSAGE_MAP()


// ����������� ��������� CAppDlg


BOOL CAppDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  �������� �������������� �������������

	int selected = ((CMainFrame*)AfxGetMainWnd())->m_pTreeView->m_iSelected;
	CString str;
	str.Format(_T("%i"), selected);

	AfxMessageBox(str);


	return TRUE;  // return TRUE unless you set the focus to a control
				  // ����������: �������� ������� OCX ������ ���������� �������� FALSE
}


void CAppDlg::Update()
{
	int selected = ((CMainFrame*)AfxGetMainWnd())->m_pTreeView->m_iSelected;
	CString str;
	str.Format(_T("%i"), selected);

	AfxMessageBox(str);
}
