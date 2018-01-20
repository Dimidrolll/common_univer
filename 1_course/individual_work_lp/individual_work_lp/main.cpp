#include <iostream>
#include <string>
#include <conio.h>
using namespace std;
int const M = -100, m = -10;
struct Node
{
  int Data;
  Node *Next;
};
typedef Node *PNode;

//удаление
void DeleteNode(PNode &head, PNode Old)
{
  PNode q = head;
  if (head == Old) {
    head = Old -> Next;
  }else{
    while (q && q ->Next != Old)
      q = q ->Next;
    if (q) 
      q ->Next = Old ->Next;
  }
  delete Old;
}

//добавление
void add(int x, PNode &head)
{
  PNode MyNode;
  if (head == NULL){
    head = new Node;
    MyNode = head;
    head ->Next = NULL;
  } else {
    MyNode = new Node;
    MyNode ->Next = head;
    head = MyNode;
  }
  MyNode ->Data = x;
}

//замена конструкций M(a,b), m(a,b) на результат
void replace(PNode &head)
{
  PNode t;
  int x = 0;

  if (head ->Data > 0 && head ->Next ->Data > 0 && head ->Next ->Next ->Data == M)
    x = (head ->Data >= head ->Next ->Data) ? head ->Data : head ->Next ->Data;
  
  if (head ->Data > 0 && head ->Next ->Data > 0 && head ->Next ->Next ->Data == m)
    x = (head ->Data <= head ->Next ->Data) ? head ->Data : head ->Next ->Data;
    
  
  t = head;
  DeleteNode(head, t);
  t = head;
  DeleteNode(head, t);
  head ->Data = x;
 
}


void main()
{
  setlocale(0,"");//обрусение :)
  
  
  PNode p1 = NULL;
  string input;
  cout << "ƒобрый день/вечер/ночь/утро. ¬ведите корректное выражение." << endl;
  cin >> input;//т.к. пробелов нет
  int i, q = 0, num = 0;
  
  for (i = 0; i < input.size() - 1; ++i){
    if (input[i] == 'M') {//все числа целые и положительные, занчит можно дл€ простоты закодировать M и m отрицательными числами
      add(M, p1);
      ++num;
    }

    if (input[i] == 'm') {
      add(m, p1);
      ++num;
    }
    
    if (input[i] >= '0' && input[i] <= '9'){
      int q=0;
      while (input[i] >= '0' && input[i] <= '9'){//посимвольное восстановление числа и добавление его в стек
        q += input[i] - 48;
        ++i;
        if (input[i] >= '0' && input[i] <= '9') 
          q *= 10;
      }
      --i;
      add(q,p1);
      ++num;
      q = 0; 
    }
    if ((p1 ->Data > 0 && p1 ->Next ->Data > 0 && p1 ->Next ->Next ->Data == M || 
      p1 ->Data > 0 && p1 ->Next ->Data > 0 && p1 ->Next ->Next ->Data == m) && num > 2)
      replace(p1);
  } 

  cout << "ќтвет: " << p1 ->Data << endl;

  getch();
}