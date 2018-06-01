
// AppView.h: интерфейс класса CAppView
//

#pragma once
#include "AppDoc.h"

class CAppView : public CFormView
{
protected: // создать только из сериализации
	CAppView();
	DECLARE_DYNCREATE(CAppView)

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
};

#ifndef _DEBUG  // версия отладки в AppView.cpp
inline CAppDoc* CAppView::GetDocument() const
   { return reinterpret_cast<CAppDoc*>(m_pDocument); }
#endif



