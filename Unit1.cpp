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
			Label3->Caption = "Исходная строка :" ;
			Button2->Caption = "Перевернуть строку" ;
		}else{
			Label3->Caption = "Перевернутая строка :" ;
			Button2->Caption = "Вернуть строку" ;
		}
	}

	Edit3->Text = String(directString.c_str());
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormCreate(TObject *Sender)
{
	Memo1->Clear() ;
	Memo1->Lines->Add("SELECT Рейсы.Номер, Машины.Номер, Водители.ФИО, Рейсы.Пробег, Рейсы.Продолжительность, Рейсы.ДатаРейса") ;
	Memo1->Lines->Add("FROM Рейсы") ;
	Memo1->Lines->Add("INNER JOIN Машины AS Машины ON Машины.Код = Рейсы.КодМашины") ;
	Memo1->Lines->Add("INNER JOIN Водители AS Водители ON Водители.Код = Машины.КодВодителя") ;
	Memo1->Lines->Add("WHERE Рейсы.ДатаРейса = '20060102'") ;

	Memo2->Clear() ;
	Memo2->Lines->Add("Так как СУБД неизвестно, предполагаем, что возможны как минимум два варианта решения:") ;
	Memo2->Lines->Add("Вариант1:") ;
	Memo2->Lines->Add("одним SQL запросом") ;
	Memo2->Lines->Add("UPDATE ЗаявкиНаДоставку AS ЗаявкиНаДоставку") ;
	Memo2->Lines->Add("INNER JOIN (") ;
	Memo2->Lines->Add("SELECT Клиенты.КодКлиента, Клиенты.Адрес") ;
	Memo2->Lines->Add("FROM Клиенты AS Клиенты") ;
	Memo2->Lines->Add("		) AS cl_q ON cl_q.КодКлиента = ЗаявкиНаДоставку.КодКлиента") ;
	Memo2->Lines->Add("SET ЗаявкиНаДоставку.Адрес = cl_q.Адрес") ;
	Memo2->Lines->Add("") ;
	Memo2->Lines->Add("Однако, некоторые СУБД не поддерживают подобных запросов, например, Firebird 2.5") ;
	Memo2->Lines->Add("Поэтому вариант 2:") ;
	Memo2->Lines->Add("На форму добавляем компоненты для работы с БД, например, через ADO") ;
	Memo2->Lines->Add("В ADOQuery добавляем текст запроса:") ;
	Memo2->Lines->Add("SELECT Клиенты.КодКлиента, Клиенты.Адрес") ;
	Memo2->Lines->Add("FROM Клиенты AS Клиенты") ;
	Memo2->Lines->Add("Затем перебором результата при помощи цикла") ;
	Memo2->Lines->Add("ADOQuery1->First() ;") ;
	Memo2->Lines->Add("	while(!ADOQuery1->Eof)") ;
	Memo2->Lines->Add("	{") ;
	Memo2->Lines->Add("		String clCode = ADOQuery1->FieldByName(""КодКлиента"")->AsString,") ;
	Memo2->Lines->Add("		String addr = ADOQuery1->FieldByName(""Адрес"")->AsString, ;") ;
	Memo2->Lines->Add("		ADOCommand1->CommandText = String(update ЗаявкиНаДоставку") ;
	Memo2->Lines->Add("			SET Адрес = '"" + addr + ""'") ;
	Memo2->Lines->Add("			WHERE  = КодКлиента '"" + clCode + ""'") ;
	Memo2->Lines->Add("		ADOCommand1->Execute() ;") ;
	Memo2->Lines->Add("		ADOQuery1->Next() ;") ;
	Memo2->Lines->Add("	}") ;
	Memo2->Lines->Add("Вариант 3: реализация процедурой внутри СУБД") ;

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
