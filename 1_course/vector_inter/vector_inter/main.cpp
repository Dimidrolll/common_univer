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
    cout << "�������� ��������:" << endl << "1.�������� �������" << endl << "2.������� �������" << endl << "3.������� ������� � ������� N" << endl <<
    "4.�������  ���������� �������" << endl << "5.������� ���������� ���������" << endl << "6.�������� ������" << endl << "7.�����" << endl; 
    cin >> a;
    if (a == 1){
      cout << "������� ����������� �������" << endl;
      int t;
      cin >> t;
      v.push_back(t);fb
    }
    if (a == 2){
      v.pop_back();
      cout << "������ ��������� �������" << endl;
    }
    if (a == 3){
      cout << "������� ����� ��������, ������� ����� �������" << endl;
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
      
      cout << "����������� " << v.size() << endl;
    }
    if (a == 6){
      v.clear();
      cout << "������ ������" << endl;
    }

    if (a == 7) return;
  }
  //getch();
}