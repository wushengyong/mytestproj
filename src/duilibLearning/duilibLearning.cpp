// duilibLearning.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#include "duilibLearning.h"

using namespace DuiLib;


class CFrameWnd : public WindowImplBase
{
public:
	virtual CDuiString GetSkinFolder(){ return L""; }
	virtual CDuiString GetSkinFile() { return L"duilib.xml"; }
	virtual LPCTSTR GetWindowClassName(void) const { return L"CFrameWnd";}
};

int APIENTRY _tWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPTSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
	CPaintManagerUI::SetInstance( hInstance ) ;
	CPaintManagerUI::SetResourcePath( CPaintManagerUI::GetInstancePath() ) ;
	CFrameWnd    duiFrme;
	duiFrme.Create( NULL , _T("DUIWnd") , UI_WNDSTYLE_FRAME ,  WS_EX_WINDOWEDGE ) ;
	duiFrme.ShowModal ();
	return 0;
}


