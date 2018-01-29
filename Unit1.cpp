//---------------------------------------------------------------------------

#include <vcl.h>
#include <string>
#include <list>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
String baseString ;
int step ;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void swap(int *iA, int *iB){
	*iA = *iA + *iB ;
	*iB = *iA - *iB ;
	*iA = *iA - *iB ;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
	int varA = StrToInt(Edit1->Text) ;
	int varB = StrToInt(Edit2->Text) ;

	swap(&varA, &varB) ;

	Edit1->Text = IntToStr(varA) ;
	Edit2->Text = IntToStr(varB) ;
}
//---------------------------------------------------------------------------
std::string ReverseStringStr(std::string &sString){
	int strLn = strlen(sString.c_str()) ;
	char *mass = new char[sString.length() + 1] ;
	if(mass == NULL){
		Form1->Edit3->Text = "No free memory" ;
		return "" ;
	}
	strcpy(mass, sString.c_str()) ;

	int i = strLn ;
	int j = 0 ;
	char *massRev = new char[sString.length() + 1] ;
	while(i >= 0){
		massRev[j] = mass[i - 1] ;
		j++ ;
		i-- ;
	}

	std::string revString ;
	sString = "" ;
	for(j = 0; j < strLn; j++)
		sString = sString + massRev[j] ;

	return revString ;
}
//---------------------------------------------------------------------------
bool ReverseString(std::string &sString){
	int strLn = strlen(sString.c_str()) ;
	char *mass = new char[sString.length() + 1] ;
	if(mass == NULL){
		Form1->Edit3->Text = "No free memory" ;
		return false ;
	}
	strcpy(mass, sString.c_str()) ;

	int i = strLn ;
	int j = 0 ;
	char *massRev = new char[sString.length() + 1] ;
	while(i >= 0){
		massRev[j] = mass[i - 1] ;
		j++ ;
		i-- ;
	}

	sString = "" ;
	for(j = 0; j < strLn; j++)
		sString = sString + massRev[j] ;

	return true ;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button2Click(TObject *Sender)
{
	step++ ;
	AnsiString dirString = String(Edit3->Text.c_str()) ;
	if (1 == step)
		baseString = dirString ;

	std::string directString = dirString.c_str() ;

	if(ReverseString(directString)){
		if(baseString != dirString){
			Label3->Caption = "�������� ������ :" ;
			Button2->Caption = "����������� ������" ;
		}else{
			Label3->Caption = "������������ ������ :" ;
			Button2->Caption = "������� ������" ;
		}
	}

	Edit3->Text = String(directString.c_str());
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormCreate(TObject *Sender)
{
	Memo1->Clear() ;
	Memo1->Lines->Add("SELECT �����.�����, ������.�����, ��������.���, �����.������, �����.�����������������, �����.���������") ;
	Memo1->Lines->Add("FROM �����") ;
	Memo1->Lines->Add("INNER JOIN ������ AS ������ ON ������.��� = �����.���������") ;
	Memo1->Lines->Add("INNER JOIN �������� AS �������� ON ��������.��� = ������.�����������") ;
	Memo1->Lines->Add("WHERE �����.��������� = '20060102'") ;

	Memo2->Clear() ;
	Memo2->Lines->Add("��� ��� ���� ����������, ������������, ��� �������� ��� ������� ��� �������� �������:") ;
	Memo2->Lines->Add("�������1:") ;
	Memo2->Lines->Add("����� SQL ��������") ;
	Memo2->Lines->Add("UPDATE ���������������� AS ����������������") ;
	Memo2->Lines->Add("INNER JOIN (") ;
	Memo2->Lines->Add("SELECT �������.����������, �������.�����") ;
	Memo2->Lines->Add("FROM ������� AS �������") ;
	Memo2->Lines->Add("		) AS cl_q ON cl_q.���������� = ����������������.����������") ;
	Memo2->Lines->Add("SET ����������������.����� = cl_q.�����") ;
	Memo2->Lines->Add("") ;
	Memo2->Lines->Add("������, ��������� ���� �� ������������ �������� ��������, ��������, Firebird 2.5") ;
	Memo2->Lines->Add("������� ������� 2:") ;
	Memo2->Lines->Add("�� ����� ��������� ���������� ��� ������ � ��, ��������, ����� ADO") ;
	Memo2->Lines->Add("� ADOQuery ��������� ����� �������:") ;
	Memo2->Lines->Add("SELECT �������.����������, �������.�����") ;
	Memo2->Lines->Add("FROM ������� AS �������") ;
	Memo2->Lines->Add("����� ��������� ���������� ��� ������ �����") ;
	Memo2->Lines->Add("ADOQuery1->First() ;") ;
	Memo2->Lines->Add("	while(!ADOQuery1->Eof)") ;
	Memo2->Lines->Add("	{") ;
	Memo2->Lines->Add("		String clCode = ADOQuery1->FieldByName(""����������"")->AsString,") ;
	Memo2->Lines->Add("		String addr = ADOQuery1->FieldByName(""�����"")->AsString, ;") ;
	Memo2->Lines->Add("		ADOCommand1->CommandText = String(update ����������������") ;
	Memo2->Lines->Add("			SET ����� = '"" + addr + ""'") ;
	Memo2->Lines->Add("			WHERE  = ���������� '"" + clCode + ""'") ;
	Memo2->Lines->Add("		ADOCommand1->Execute() ;") ;
	Memo2->Lines->Add("		ADOQuery1->Next() ;") ;
	Memo2->Lines->Add("	}") ;
	Memo2->Lines->Add("������� 3: ���������� ���������� ������ ����") ;

	Memo3->Clear() ;
	Memo3->Lines->Add("class TAddList: public list<int>{") ;
	Memo3->Lines->Add("public:") ;
	Memo3->Lines->Add("void AddToEnd ( const int & iValue ){") ;
	Memo3->Lines->Add("	if (!empty() && back() == iValue)") ;
	Memo3->Lines->Add("		++back();") ;
	Memo3->Lines->Add("	else push_back(iValue);") ;
	Memo3->Lines->Add("}") ;
	Memo3->Lines->Add("};") ;

}
//---------------------------------------------------------------------------
