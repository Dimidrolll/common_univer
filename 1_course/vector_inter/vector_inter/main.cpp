#include <iostream>
#include <vector>
#include <conio.h>
#include <iterator>

using namespace std;

void main()
{
  setlocale(0,"");
  vector <int> v;
  vector <int> :: iterator it;
  v.begin();
  int a;
  while (1){
    cout << "Выберете действие:" << endl << "1.Добавить элемент" << endl << "2.Удалить элемент" << endl << "3.Вывести элемент с номером N" << endl <<
    "4.Вывести  содержимое вектора" << endl << "5.Вывести количество элементов" << endl << "6.Очистить вектор" << endl << "7.Выход" << endl; 
    cin >> a;
    if (a == 1){
      cout << "Введите добавляемый элемент" << endl;
      int t;
      cin >> t;
      v.push_back(t);fb
    }
    if (a == 2){
      v.pop_back();
      cout << "Удален последний элемент" << endl;
    }
    if (a == 3){
      cout << "Введите номер элемента, который нужно вывести" << endl;
      int t;
      cin >> t;
      it = v.begin();
      it += t - 1; 
      cout << *it << endl;
      it = v.begin();
    }
    if (a == 4){
      for (it = v.begin(); it < v.end(); ++it)
        cout << *it << ' ';
      cout << endl;
      it = v.begin();
    }
    if (a == 5){
      
      cout << "Размерность " << v.size() << endl;
    }
    if (a == 6){
      v.clear();
      cout << "Вектор очищен" << endl;
    }

    if (a == 7) return;
  }
  //getch();
}