//---------------------------------------------------------------------------


#pragma hdrstop

#include "SYSyncThread.h"

//---------------------------------------------------------------------------

#pragma package(smart_init)

__fastcall SYSyncThread::SYSyncThread()
: TThread(true)
{
    m_onEvent = NULL;
    this->FreeOnTerminate=true;

}


void __fastcall SYSyncThread::Execute(void)
{
    wchar_t wszBuf[32];
    for (int i = 0; i < 20; i++)
    {
        Sleep(100);
        Synchronize(Sync);
        wchar_t wszBuf[256];
        memset(wszBuf, 0, sizeof(wszBuf));
        wsprintf(wszBuf, L"%d", i);
        OutputDebugString(wszBuf);
    }
}

void __fastcall SYSyncThread::Sync(void)
{
    if (m_onEvent) {
        m_onEvent(this);
    }

}

void __fastcall SYSyncThread::DelayWithMilliSecond(unsigned int ms)
{
    DWORD dwBeginTime = GetTickCount();
    while(true)
    {
    	DWORD dwCurTime = GetTickCount();
    	if((dwCurTime - dwBeginTime) > ms)
    	{
    		break;
    	}
    	//Dovenets
    	MSG msg;
    	while (PeekMessage( & msg, NULL,  0 ,  0 , PM_REMOVE))
    	{
    		TranslateMessage( & msg);
    		DispatchMessage( & msg);
    	}
    }
}

