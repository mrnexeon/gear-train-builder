#pragma once


// диалоговое окно CAppDlg

class CAppDlg : public CDialog
{
	DECLARE_DYNAMIC(CAppDlg)

public:
	CAppDlg(CWnd* pParent = NULL);   // стандартный конструктор
	virtual ~CAppDlg();

// Данные диалогового окна
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_APP_FORM };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // поддержка DDX/DDV

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	void Update();
	
	afx_msg void OnEnChangeEdit3();
	afx_msg void OnEnChangeEdit7();
};
