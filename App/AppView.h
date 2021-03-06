
// AppView.h: интерфейс класса CAppView
//

#pragma once
#include "AppDoc.h"

class CAppView : public CFormView
{
protected: // создать только из сериализации
	CAppView();
	DECLARE_DYNCREATE(CAppView)
	CStatic _image;
	double m_DiametrVnechShest= 600.0;
	double m_DiametrVnytrShest = 150.0;
	double m_nZyb = 32;
	double m_ShirinaShest = 80.0;
	double m_DiametrVnechShest2 = 800.0;
	double m_DiametrVnytrShest2 = 200.0;
	double m_nZyb2 = 36;
	double m_ShirinaShest2 = 80.0;
	double m_DiametrVnechPodship = 120.0;
	double m_nPoship = 20;
	double m_DiametrVnytrPodship = 80.0;
	double m_DiametrVnechPodship2 = 150.0;
	double m_nPoship2 = 26;
	double m_DiametrVnytrPodship2 = 100.0;

	double m_DlinaVala1 = 100.0;
	double m_DlinaVala2 = 125.0;
	double m_DlinaVala12 = 200.0;
	double m_DlinaVala22 = 250.0;
	

public:
	void Update();
#ifdef AFX_DESIGN_TIME
	enum{ IDD = IDD_APP_FORM };
#endif

// Атрибуты
public:
	CAppDoc* GetDocument() const;

// Операции
public:

// Переопределение
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // поддержка DDX/DDV
	virtual void OnInitialUpdate(); // вызывается в первый раз после конструктора
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnPrint(CDC* pDC, CPrintInfo* pInfo);

// Реализация
public:
	virtual ~CAppView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Созданные функции схемы сообщений
protected:
	DECLARE_MESSAGE_MAP()
public:

	afx_msg void On32771();
	afx_msg void On32772();
	afx_msg void On32773();
	afx_msg void On32774();
	afx_msg void OnBnClickedButton1();
};

#ifndef _DEBUG  // версия отладки в AppView.cpp
inline CAppDoc* CAppView::GetDocument() const
   { return reinterpret_cast<CAppDoc*>(m_pDocument); }
#endif



