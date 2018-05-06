#include "stdafx.h"
#include "Inventor.h"

using namespace InventorNative;

CComPtr<Application> p_invApp = nullptr;

void InitializeInventor() {
	CLSID InvAppClsid;
	HRESULT hRes = CLSIDFromProgID(L"Inventor.Application", &InvAppClsid);

	// ��������, ������� �� �������� ����������

	if (FAILED(hRes)) {
		p_invApp = nullptr;
		return;
	}

	// ��������, �������� �� ����������

	CComPtr<IUnknown> pInvAppUnk = nullptr;

	hRes = ::GetActiveObject(InvAppClsid, NULL, &pInvAppUnk);
	if (FAILED(hRes)) {

		// ���� �� �������� - ���������

		TRACE(L"Could not get hold of an active Inventor, will start a new session\n"); // ��������������

		hRes = CoCreateInstance(
			InvAppClsid, // ID
			NULL,
			CLSCTX_LOCAL_SERVER,
			__uuidof(IUnknown),
			(void **)&pInvAppUnk);

		// ���������, ����������� ��

		if (FAILED(hRes)) {
			p_invApp = nullptr;
			return;
		}
	}

	// �������� ��������� �� ���������� ���������� (hRes)
	// ���� ���������� ��������� ������ �� ��������� ��� ���������� � � ��� �� ���� ������ ������

	if (!p_invApp)
		hRes = pInvAppUnk->QueryInterface(__uuidof(Application), (void **)&p_invApp);

	if (FAILED(hRes)) {
		return;
	}

	p_invApp->put_Visible(TRUE); // ���������� ����������
}