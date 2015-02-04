// duilibLearning.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#include "duilibLearning.h"

using namespace DuiLib;

#define     DUI_MSGTYPE_DBCLICK      _T("dbclick")

// 使之能够响应双击消息
class CDBButtonUI : public CButtonUI
{
public :
	virtual void DoEvent(TEventUI& event)
	{
		if (event.Type == UIEVENT_DBLCLICK)
		{
			m_pManager->SendNotify ( this ,  DUI_MSGTYPE_DBCLICK ,  event.wParam ,   event.lParam);
			return;
		}
		__super::DoEvent(event) ; 
	}
};
class CDuiFrameWnd : public WindowImplBase
{
protected :
	virtual CDuiString GetSkinFolder() { return _T("resource/") ; }
	virtual CDuiString GetSkinFile() { return _T("duilib.xml") ; }
	virtual LPCTSTR GetWindowClassName() const { return _T("CDuiFrameWnd") ; }
};

int APIENTRY _tWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPTSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
	CPaintManagerUI::SetInstance( hInstance ) ;
	CPaintManagerUI::SetResourcePath( CPaintManagerUI::GetInstancePath() ) ;
	CDuiFrameWnd    duiFrme;
	duiFrme.Create( NULL , _T("DUIWnd") , UI_WNDSTYLE_FRAME ,  WS_EX_WINDOWEDGE ) ;
	duiFrme.ShowModal ();
	return 0;
}


