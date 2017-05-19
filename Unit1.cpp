//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
#include "Unit2.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
A obj;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
    Memo1->Clear();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender) //Создать дерево
{
    if(root != NULL) 
        obj.Del_Tree(root);
    root = obj.List (StrToInt(Edit1->Text));
    Button3Click(Sender);
    Edit1->Clear();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button3Click(TObject *Sender) //Просмотреть дерево
{
    Memo1->Clear();
    if (root == NULL) {
        ShowMessage(" Create TREE !");
    }else {
        Memo1->Lines->Add("---------- View -----------");
        obj.View_Tree(root, 0, Memo1);
    }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button2Click(TObject *Sender) //Добавить узел
{
     if (root == NULL) { 
         root = obj.List (StrToInt(Edit1->Text));
     }
     else {
	 obj.Add_List(root, StrToInt(Edit1->Text));
     }
    Button3Click(Sender);
    Edit1->Clear();
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Button4Click(TObject *Sender) //Удалить заданный узел
{
    int Del_Node = StrToInt(Form1->Edit1->Text);
    root = obj.Del_Info(root, Del_Node);
    Button3Click(Sender);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button5Click(TObject *Sender) //Минимальный элемент
{
    Memo1->Clear();
    Tree *Min_Node = obj.Min_Key(root);
    Memo1->Lines->Add(Min_Node->info);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button6Click(TObject *Sender) //Максимальный элемент
{
    Memo1->Clear();
    Tree *Max_Node = obj.Max_Key(root);
    Memo1->Lines->Add(Max_Node->info);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button7Click(TObject *Sender) //Кол-во листьев
{
    Memo1->Clear();
    Memo1->Lines->Add(obj.List_Count(root));
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button8Click(TObject *Sender) //Удалить дерево целиком
{
    obj.Del_Tree(root);
    Memo1->Clear();
    Edit1->Clear();
    ShowMessage(" Tree Delete!");
    root = NULL;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button9Click(TObject *Sender) //Печать по возрастанию
{
    Memo1->Clear();
    obj.Left_Order(root, Memo1);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button10Click(TObject *Sender) //Печать по убыванию
{
    Memo1->Clear();
    obj.Right_Order(root, Memo1);
}
//---------------------------------------------------------------------------


