//---------------------------------------------------------------------------

#ifndef Unit2H
#define Unit2H
#include <vcl.h>
#include <iostream.h>
#include <string.h>
#include "Unit1.h"

//---------------------------------------------------------------------------
#endif

struct Tree {
    int info;
    Tree *left, *right;
}*root;

class A {
public:
    void Add_List(Tree*, int);
    void View_Tree (Tree*, int, TMemo*);
    Tree* Del_Info(Tree*, int);
    void Del_Tree(Tree*);
    Tree* List(int);
    Tree* Min_Key(Tree*);
    Tree* Max_Key(Tree*);
    int List_Count(Tree*);
    void Left_Order(Tree*, TMemo*);
    void Right_Order(Tree*, TMemo*);
};

Tree* A::List(int inf)//Формирование дерева поиска
{
    Tree *Create_Tree = new Tree;
    Create_Tree->info = inf;
    Create_Tree->left = Create_Tree->right = NULL;
    return Create_Tree;
}

void A::Add_List(Tree *root, int key)//Добавление узла
{
    Tree*prev,*node;
    bool find = true;
    node = root;
    while (node && find) {
        prev = node;
	if (key == node->info) {
	    find = false;
	    ShowMessage("Dublucate Key!");
	}else node = key < prev->info ? prev->left : prev->right;
}
    if (find) {
	node = List(key);
	(key < prev->info ? prev->left : prev->right) = node;
	}
    }
}

void A::View_Tree(Tree *print, int level, TMemo *Memo1 )//Вывод дерева на экран
{
    String str_level;
    if (print) {
        View_Tree (print->right , level+1, Memo1);
	for (int i=0; i<level; i++) 
	    str_level = str_level + "    ";
	Memo1->Lines->Add(str_level + IntToStr(print->info));
	View_Tree(print->left, level+1, Memo1);
     }
}

void A::Del_Tree(Tree *Del)//Очистить память(удалить дерево целиком)
{
    if (Del != NULL) {
	Del_Tree (Del->left);
        Del_Tree (Del->right);
	delete Del;
     }
}

Tree* A::Del_Info(Tree *root, int key)//Удаление заданного узла
{
    Tree *Del, *Prev_Del, *Node, *Prev_Node;
    // Del, Prev_Del – удаляемый узел и его предыдущий (предок);
    // Node, Prev_Node – элемент, на который заменяется удаленный, и его предок;
    Del = root;
    Prev_Del = NULL;
    while (Del != NULL && Del->info != key) {
	Prev_Del = Del;
	Del = del->info > key ? Del->left : Del->right;
    }
    if (Del == NULL) {
	ShowMessage ( "NOT Key!");
	return root;
    }
    if (Del->right == NULL) {
        Node = Del->left;//Поиск элемента Node для замены
    }else if (Del->left == NULL) {
              Node = Del->right;
          }else {
       	      Prev_Node = Del;//Ищем самый правый узел в левом поддереве
	      Node = Del->left;
	      while (Node->right != NULL) {	
                  Prev_Node = Node;
		  Node = Node->right;
	      }
	      if (Prev_Node == Del) {
	          Node->right = Del->right;// Нашли элемент для замены Node и его предка Prev_Node
	      }else {
                  Node->right = Del->right;
		  Prev_Node->right = Node->left;
		  Node->left = Prev_Node;
       	      }
	}
    if (Del == root) {//Поддерево R присоединяем к предку удаляемого узла
        root = Node;
    }else (Del->info < Prev_Del->info : Prev_Del->left : Prev_Del->right) = Node;
    delete Del;
    return root;
}

Tree* A::Min_Key(Tree *min)//Находим минимальный узел
{
    while (min->left != NULL)
	min = min->left;
    return min;
}

Tree* A::Max_Key(Tree *max)//Находим максимальный узел
{
    while (max->right != NULL)
	max = max->right;
    return max;
}

int A::List_Count(Tree* root)//Количество листьев в дереве
{
    if (!root)
        return 0;
    if (!root->left && !root->right)
        return 1;
    return List_Count(root->left) + List_Count(root->right);
}

void A::Left_Order(Tree* root, TMemo *Memo1)//Вывести по возрастанию
{
    if (root->left)
        Left_Order(root->left, Memo1);
        Memo1->Lines->Add(root->info);
    if (root->right)
        Left_Order(root->right, Memo1);
}

void A::Right_Order(Tree* root, TMemo *Memo1)//Вывести по убыванию
{
    if (root->right)
        Right_Order(root->right, Memo1);
        Memo1->Lines->Add(root->info);
    if (root->left)
        Right_Order(root->left, Memo1);
}




