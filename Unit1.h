//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Data.Win.ADODB.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TGroupBox *GroupBox1;
	TEdit *Edit2;
	TButton *Button1;
	TLabel *Label2;
	TLabel *Label1;
	TEdit *Edit1;
	TGroupBox *GroupBox2;
	TLabel *Label3;
	TButton *Button2;
	TEdit *Edit3;
	TGroupBox *GroupBox3;
	TMemo *Memo1;
	TGroupBox *GroupBox4;
	TMemo *Memo2;
	TGroupBox *GroupBox5;
	TMemo *Memo3;
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall Button2Click(TObject *Sender);
	void __fastcall FormCreate(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
