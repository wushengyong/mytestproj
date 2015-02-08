// duilibLearning.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#include "duilibLearning.h"

using namespace DuiLib;


class CFrameWnd : public WindowImplBase
{
public:
	virtual CDuiString GetSkinFolder(){ return L"resource\\skin"; }
	virtual CDuiString GetSkinFile() { return L"Control.xml"; }
	virtual LPCTSTR GetWindowClassName(void) const { return L"CFrameWnd";}
	virtual void InitWindow()
	{
		CActiveXUI* pActiveXUI = static_cast<CActiveXUI*>(m_PaintManager.FindControl(L"ActiveXDemo1"));
		if (pActiveXUI != NULL)
		{
			IWebBrowser2* pWebBrowser = NULL;
			pActiveXUI->SetDelayCreate(false);
			pActiveXUI->CreateControl(CLSID_WebBrowser);
			pActiveXUI->GetControl(IID_IWebBrowser2,(void**)&pWebBrowser);
			if (pWebBrowser != NULL)
			{
				pWebBrowser->Navigate(L"http://www.baidu.com",NULL,NULL,NULL,NULL);
				pWebBrowser->Release();
			}
		}
	}
};

int APIENTRY _tWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPTSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
	CPaintManagerUI::SetInstance( hInstance ) ;
	HRESULT hr = ::CoInitialize(NULL);
	if (FAILED(hr)) return 0;
	CFrameWnd    duiFrme;
	duiFrme.Create( NULL , _T("DUIWnd") , UI_WNDSTYLE_FRAME ,  WS_EX_WINDOWEDGE ) ;
	duiFrme.CenterWindow();
	duiFrme.ShowModal ();
	::CoUninitialize();
	return 0;
}


