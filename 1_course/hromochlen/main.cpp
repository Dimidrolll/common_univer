#include <iostream>
#include <fstream>
#include <conio.h>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <ctime>

using namespace std;

string rezult = "";
long int amount = 0; 

bool check_full(int **matrix, int n, bool *deleted) {//полный ли граф?
    bool mark = true;
    for (int i = 0; i < n; ++i) {
      if (!deleted[i])
        for (int j = 0; j < n; ++j) {
            if (i < j && !deleted[j])
                if (matrix[i][j] == 0)
                    mark = false;
        }
    }

    return mark;
}

void add_edge(int **matrix, int n, bool *deleted) {//добавление ребра
  int x, y;
    for (int i = 0; i < n; ++i) {
      if (!deleted[i])
        for (int j = 0; j < n; ++j) {
            if (i < j && !deleted[j])
                if (matrix[i][j] == 0) {
                    x = i;
                    y = j;
                }
        }
    }
    matrix[x][y] = matrix[y][x] = 1;
                    
}

void identify(int **matrix, int n,bool *deleted) {//отождествление 2 вершин
    int x = 0, y = 0;
    for (int i = 0; i < n; ++i) {
      if (!deleted[i])
        for (int j = 0; j < n; ++j) {
            if (i < j && !deleted[j])
                if (matrix[i][j] == 0) {
                    x = i;
                    y = j;
                }
        }
    }
    deleted[y] = true;
     for (int i = 0; i < n; ++i) {
       if (!deleted[i])
        for (int j = 0; j < n; ++j) {
          if (matrix[i][y] == 1 && !deleted[j]){
            matrix[i][x] = matrix[x][i] = 1;     
             }
        }
    }
}

void outpuT(int n, string &result, bool *deleted, int colours)//функция вывода формулы для одного полного графа
{
  int count = 0;
  int temp = 1;
  for (int i = 0; i < n; ++i)
    if (!deleted[i])
      ++count;
  for (int i = 0; i < count; ++i){
      int sys_sch = 10;
      char buffer[20];
      char *p;  
      p = itoa(i,buffer,sys_sch);
      result += "(x - ";
      result += p;
      result += ")";
      
      temp *= colours - i;
  }
    amount += temp; 
}

void chromo_polinomo(int **matrix, bool *deleted, int n, int colours)//функция для нахождения хромотического многочлена
{
  
  if (check_full(matrix,n,deleted)){
    string str;
    outpuT(n, str,deleted, colours);
    rezult += str;
    rezult += " + ";
    return; 
  } else {
    int **copy_matrix = new int *[n];//создания копии массива
    for (int i = 0; i < n; ++i) 
        copy_matrix[i] = new int[n];
    bool *copy_deleted = new bool [n];

    for (int i = 0; i < n; ++i) {
      copy_deleted[i] = deleted[i];
        for (int j = 0; j < n; ++j) 
          copy_matrix[i][j] = matrix[i][j];
    }
    add_edge(matrix, n, deleted);    
    chromo_polinomo(matrix, deleted, n, colours);
    identify(copy_matrix, n, copy_deleted);
    chromo_polinomo(copy_matrix, copy_deleted, n, colours);
  }
}


int main() {
    setlocale(0,"");
    clock_t start_time =  clock();// начало отсчета времени
    ifstream inputF("input.txt");
    ofstream outputF("output.txt");
    int n, colours;

    inputF >> n;
    bool *deleted = new bool [n];
    for (int i = 0; i < n; ++i)
      deleted[i] = false;
    int **matrix = new int *[n];//выделение памяти
    for (int i = 0; i < n; ++i) {
        matrix[i] = new int[n];
    }

    for (int i = 0; i < n; ++i) {//ввод матрицы
        for (int j = 0; j < n; ++j) {
            inputF >> matrix[i][j];
        }
    }
    inputF >> colours;

    
    chromo_polinomo(matrix, deleted, n, colours);
    rezult.erase(rezult.end() - 2);
    outputF << rezult << endl << amount;
    inputF.close();
    outputF.close();
    
    clock_t end_time = clock(); //конец отсчета
    clock_t search_time = end_time - start_time;
    cout << "runtime = " << search_time/1000.0 << endl;
  getch();
}