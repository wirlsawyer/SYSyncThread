//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
#include "SYSyncThread.h"

SYSyncThread *g_thread1 = new SYSyncThread();
SYSyncThread *g_thread2 = new SYSyncThread();
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
    g_thread1->OnDidEvent = OnDidEvent;
    g_thread2->OnDidEvent = OnDidEvent;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::OnDidEvent(TObject* sender)
{
   if (sender == g_thread1) {
      //for (int i = 0; i < 10; i++) {
       Button1->Left += 10;
       //g_thread1->DelayWithMilliSecond(100);
    //}
   }

   if (sender == g_thread2) {
      //for (int i = 0; i < 10; i++) {
       Button1->Top += 10;
       //g_thread2->DelayWithMilliSecond(100);
    //}
   }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
	g_thread1->Resume();
        g_thread2->Resume();
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Button2Click(TObject *Sender)
{
   	g_thread1->Suspend();
        g_thread2->Suspend();
}
//---------------------------------------------------------------------------

