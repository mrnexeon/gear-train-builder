#include "stdafx.h"
#include "Inventor.h"

using namespace InventorNative;

CComPtr<Application> p_invApp = nullptr;

void InitializeInventor() {
	CLSID InvAppClsid;
	HRESULT hRes = CLSIDFromProgID(L"Inventor.Application", &InvAppClsid);

	// ѕроверка, удалось ли получить приложение

	if (FAILED(hRes)) {
		p_invApp = nullptr;
		return;
	}

	// ѕроверка, запущено ли приложение

	CComPtr<IUnknown> pInvAppUnk = nullptr;

	hRes = ::GetActiveObject(InvAppClsid, NULL, &pInvAppUnk);
	if (FAILED(hRes)) {

		// ≈сли не запущено - запускаем

		TRACE(L"Could not get hold of an active Inventor, will start a new session\n"); // ѕредупреждение

		hRes = CoCreateInstance(
			InvAppClsid, // ID
			NULL,
			CLSCTX_LOCAL_SERVER,
			__uuidof(IUnknown),
			(void **)&pInvAppUnk);

		// ѕровер€ем, запустилось ли

		if (FAILED(hRes)) {
			p_invApp = nullptr;
			return;
		}
	}

	// ѕолучаем указатель на запущенное приложение (hRes)
	// если происходит повторный запуск то указатель уже существует и с ним не надо ничего делать

	if (!p_invApp)
		hRes = pInvAppUnk->QueryInterface(__uuidof(Application), (void **)&p_invApp);

	if (FAILED(hRes)) {
		return;
	}

	p_invApp->put_Visible(TRUE); // –азвернуть приложение
}