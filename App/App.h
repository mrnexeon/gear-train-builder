
// App.h: основной файл заголовка для приложения App
//
#pragma once

#ifndef __AFXWIN_H__
	#error "включить stdafx.h до включения этого файла в PCH"
#endif

#include "resource.h"       // основные символы


// CAppApp:
// Сведения о реализации этого класса: App.cpp
//

class CAppApp : public CWinApp
{
public:
	CAppApp();


// Переопределение
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Реализация
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CAppApp theApp;
