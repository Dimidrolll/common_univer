#include <iostream>
#include <fstream>
#include <string>
#include <conio.h>

using namespace std;

//void Sort(students **p, int N)
//    { 
//      for (int i=N-1; i>0; i--)
//      for (int j=0; j<i; j++)
//      if (p[j]->fio > p[j+1]->fio)
//      { 
//        Worker *temp;
//        temp = p[j];
//        p[j] = p[j+1];
//        p[j+1] = temp; 
//      }
//    }
void main ()
{
  setlocale(LC_ALL, "Russian");
  struct students
  {
    string fame;
    string name;
    short int phys;
    short int math;
    short int inf;

  };
  //int const n = 5;
  students student[100];
  fstream finp_stand, f_bin;
  finp_stand.open("input.txt",ios::in);
  f_bin.open("a_bin.dat",ios::out|ios::binary);
  int col = 0;
  while(!finp_stand.eof()){
    finp_stand >> student[col].name >> student[col].fame >> 
      student[col].math >> student[col].inf >> student[col].phys;
    ++col;
  } 
  finp_stand.close();
  f_bin.close();
  f_bin.open("a_bin.dat",ios::in|ios::trunc|ios::out|ios::binary);
  for (int i = 0; i < col; ++i){
    f_bin.write((char *) &student[i], sizeof(student[i]));
   // cout << student[i].name << ' ' << student[i].fame << ' '  << student[i].math << ' '  << student[i].inf 
     // << ' '  << student[i].phys << endl; 
  }

    f_bin.seekg(0,0);
    students arr[100];
    students *pointer[100];
    for(int i = 0; i < col; ++i){
      f_bin.read((char* ) & arr[i], sizeof(students));
      int max = arr[i].inf + arr[i].math + arr[i].phys;
      int o = 0;
      while(o < i){
        if((pointer[o] -> inf) + (pointer[o] -> math) + (pointer[o] -> phys) < max){
          for(int a = i; a > o; --a){
            pointer[a] = &*pointer[a - 1];
          } break;
        }
        o++;
      }
      pointer[o] = &arr[i];
    }

    for(int i = 0; i < col; ++i){
    cout << pointer[i] -> name << ' ' << pointer[i] -> fame << ' ' <<
      pointer[i] -> math << ' ' << pointer[i] -> inf << ' ' << pointer[i] -> phys << endl;

  } 
  //cout << student.fame << ' ' << student.name << endl; 
  getch();
}