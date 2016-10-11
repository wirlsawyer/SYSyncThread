//---------------------------------------------------------------------------

#ifndef SYSyncThreadH
#define SYSyncThreadH
#include <vcl.h>
//---------------------------------------------------------------------------
typedef void __fastcall (__closure *SYSyncThread_OnDidEvent)(TObject* sender);
/*
SYSyncThread *g_thread1 = new SYSyncThread();
g_thread1->OnDidEvent = OnDidEvent;
g_thread1->Resume();
void __fastcall TForm1::OnDidEvent(TObject* sender)
{

}
*/
class SYSyncThread : public TThread
{
public:
    __fastcall SYSyncThread();
    virtual void __fastcall Execute(void);
    void __fastcall DelayWithMilliSecond(unsigned int ms);
     //Event
    __property SYSyncThread_OnDidEvent OnDidEvent = { read = m_onEvent, write = m_onEvent };

private:
    void __fastcall Sync(void);  //go to main threa
private:
    //event
    SYSyncThread_OnDidEvent  m_onEvent;
    //var

};

#endif

