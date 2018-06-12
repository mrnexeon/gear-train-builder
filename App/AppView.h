
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
	double m_DiametrVnechShest= 1;
	double m_DiametrVnytrShest = 2;
	double m_nZyb = 3;
	double m_ShirinaShest = 4;
	double m_DiametrVnechShest2 = 5;
	double m_DiametrVnytrShest2 = 6;
	double m_nZyb2 = 7;
	double m_ShirinaShest2 = 8;
	double m_DiametrVnechPodship = 11;
	double m_ShirinaPoship = 10;
	double m_DiametrVnytrPodship = 9;
	double m_DiametrVnechPodship2 = 14;
	double m_ShirinaPoship2 = 13;
	double m_DiametrVnytrPodship2 = 12;
	double m_DlinaVala1 = 15;
	double m_DlinaVala2 = 16;
	double m_DlinaVala12 = 17;
	double m_DlinaVala22 = 18;
	

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



