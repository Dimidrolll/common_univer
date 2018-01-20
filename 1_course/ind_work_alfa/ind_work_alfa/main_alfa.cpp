#include <iostream>
#include <stdio.h>
#include <string>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <ctime>

using namespace std;

void nullll(char *arr1, int &m, int n);
void summa(char *arr1, int &n, char *arr2, int m);
void multiplication(char *arr1, int &n, char *arr2, int m);
bool larger(char *arr1, int al, char *arr2, int bl);
bool equality(char *arr1, int al, char *arr2, int bl);
void pervl(char *arr1, int al, char *arr2, int bl, char *ost, int &cl);
void subtraction(char *arr1, int &n, char *arr2, int &m);
void division(char *arr1,  int al,char *arr2, int bl, char *ost, int &cl,char *rez, int &dl);

int main()
{
  SetConsoleCP(1251);
  SetConsoleOutputCP(1251);

  string final_str = "";
  int  bignum_length,  bignum_length_reserve, countern = 1, ostn,         unitn_str = 1, nulln_str = 1, markn_for_sqr,     countern_for_sqr = 1, rezultn,    countern_for_sqr_d;
  char the_bignum[999],bignum_reserve[999],   counter[999], ostatok[999], unit_str[999], null_str[999], mark_for_sqr[999], counter_for_sqr[999], rezult[999],counter_for_sqr_d[999];
  bool mark = false;
  int i1 = 0,i4 = 0,i5 = 0;

  gets(the_bignum);
  
  unsigned int start_time =  clock();

 	while(the_bignum[i1] != '\0') {
	  the_bignum[i1] = int (the_bignum[i1] - 48);
    bignum_reserve[i1] = int (the_bignum[i1] - 48);
    i1++;	
	  }
  bignum_length = i1;
  bignum_length_reserve = i1;

  // тут должна быть защита от типичных юзеров
  for(i4 = 0;i4 < i1;i4++) {
	  if ((the_bignum[i4] >= 0 && the_bignum[i4] <= 9 && the_bignum[0] != 0) && (i4 == '\n')) i5++;
    else break;
	  }
  if (i5 != i1) { 
    cout << "Invalid value" << endl;
    getch();
    return 0;
  }
  
  markn_for_sqr = i1 / 2 + 1;
  for (int isqr = 0; isqr < markn_for_sqr; isqr++)
    mark_for_sqr[isqr] = 9;
  cout << endl;
  
  counter[0] = 2;
  counter_for_sqr[0] = 2;
  unit_str[0] = 1;
  null_str[0] = 0;

  while (larger(bignum_reserve,bignum_length_reserve,counter_for_sqr,countern_for_sqr) || 
    equality(bignum_reserve,bignum_length_reserve,counter_for_sqr,countern_for_sqr)) //сравниваем начальное число с самим счетчиком или с квадратом счетчика, когда это необходимо  
  {
    division(the_bignum,bignum_length,counter,countern,ostatok,ostn,rezult,rezultn);//находим остаток
    while (equality(ostatok,ostn,null_str,nulln_str) == true)//проверяем на равенство строку-остаток и нулевую строку
    {
      division(the_bignum,bignum_length,counter,countern,ostatok,ostn,rezult,rezultn);
      for (i1 = 0; i1 < bignum_length; i1++) the_bignum[i1] = 0;
      bignum_length = rezultn;                                   //тут размер частного делимому
      for (i1 = 0; i1 < rezultn; i1++) the_bignum[i1] = rezult[i1];//тут присваиваем делимому частное        
      for (i1 = 0; i1 < countern; i1++) final_str = final_str + counter[i1] ;//пишем в строку-выход строку-счетчик поэлементно
      final_str = final_str + ' ';
      mark = true;      //теперь у нас число точно не простое
      division(the_bignum,bignum_length,counter,countern,ostatok,ostn,rezult,rezultn);
    }
    summa(counter,countern,unit_str,unitn_str);//единичная строка + счетчик
    for (int i2 = 0; i2 < countern_for_sqr; i2++) counter_for_sqr[i2] = 0;
    countern_for_sqr = countern;
    for (int i2 = 0; i2 < countern_for_sqr; i2++) counter_for_sqr[i2] = counter[i2];//буферный массив для счетчика(чтоб в квадрат возводить)
    if (larger(counter_for_sqr,countern_for_sqr,mark_for_sqr, markn_for_sqr) || 
      equality(counter_for_sqr,countern_for_sqr,mark_for_sqr, markn_for_sqr)) 
      multiplication(counter_for_sqr,countern_for_sqr,counter_for_sqr,countern_for_sqr);
  }

  if (larger(the_bignum,bignum_length,unit_str, unitn_str))
    for (i1 = 0; i1 < bignum_length; i1++) final_str = final_str + (the_bignum[i1]); // выводим последния делитель, если нужно(т.е. если он оказался больше приближенного корня)

  if (mark == false) { //проверка было ли число простым
    cout << "The bignum was a simple" << endl;
    for (i1 = 0; i1 < bignum_length_reserve; i1++) cout << (int)bignum_reserve[i1] + 48;//вывод строки-выхода и самого числа 
  } 
  else { 
    cout << "The bignum was a composite" << endl; 
    for (i1 = 0; i1 < final_str.size(); i1++) 
      if (final_str[i1] != ' ') cout << (int)final_str[i1] ;
      else cout << ' ';//тут выводим строку-выход 
  }

  cout << endl;
	unsigned int end_time = clock();
	unsigned int runtime = end_time - start_time;
	cout << "runtime = " << runtime / 1000.0 << endl; 
  getch();
  return 0;
}



void nullll(char *arr1, int &m, int n) // для добавления нулей
{
 	  int i,j;
    for(i=0; i<n-m; i++)
	    for(j=n-1; j>0; j--)
        arr1[j]=arr1[j-1];
    for(i=0; i<n-m; i++)
      arr1[i]=0;    
    m=n;	
}

void summa(char *arr1, int &n, char *arr2, int m)   // сумма 2 чисел, возвращает результат в первое
{
    char c[999];
    int i,j,l,k;  
                           // Дополняем нулями
    if (n > m) nullll(arr2,m,n);
    else if (n < m) nullll(arr1,n,m);
                                // Обнуляем резултат
    for (i = 0; i < n + 1; i++)
      c[i] = 0;
    // Сложение
    k = 0; l = 0;
    for (j = n; j > 0; j--) {
 	   c[j] += (arr1[j - 1] + arr2[j - 1] + k) % 10;
     if (c[j] > 9) {
       l = 1;
       c[j] = c[j] % 10;
       }
	   k = (arr1[j - 1] + arr2[j - 1] + k) / 10 + l;        
     if (j == 1) c[0] += k;
     l = 0;
     }
                   // убираем от лишние нули
    while (c[0] == 0) {
      for (j = 0; j < n; j++)
        c[j] = c[j + 1];
      if (n != 0) n--; 
      else break;
      }
    while (arr2[0] == 0) {
      for (j = 0; j < m - 1; j++)
        arr2[j] = arr2[j + 1];
      if (m != 1) m--; 
      else break;
      }
    n++;
              // переприсваивание
    for (i = 0; i < n; i++)
      arr1[i] = c[i];
}

void multiplication(char *arr1, int &n, char *arr2, int m)       //умножение  2 чисел, результат возвращается в первое
{
    char c[999];
    int i,j,l,k;
    
    for (i = 0; i < n + m; i++)
      c[i] = 0;
                //умножение
    for (i = 0; i < m; i++) {
    k = 0; l = 0;
    for (j = n - 1; j >= 0; j--) {
 	    c[j + m - i] += (arr1[j] * arr2[m - 1 - i] + k) % 10;
      if (c[j + m - i] > 9) {
        l = c[j + m - i] / 10;
        c[j + m - i] = c[j + m - i] % 10;
        }
      k = (arr1[j] * arr2[m - i - 1] + k) / 10 + l;        
      if (j == 0) c[j + m - 1 - i] += k;
      l = 0;
      }
    }
    //избавляемся от ненужных нулей
    n = n + m;
    while (c[0] == 0) {
      for (j = 0; j < n - 1; j++)
        c[j] = c[j + 1];
      if (n != 1) n--; 
      else break;
      }
    //переприсваивание
    for (i = 0; i < n; i++)
      arr1[i] = c[i];
}

bool larger(char *arr1, int al, char *arr2, int bl) // больше
{
    int i;
    if (al > bl) return true;
    else 
      if (bl > al) return false;
    else
      for (i = 0; i < al; i++)
        if (arr1[i] > arr2[i]) return true;
        else 
          if (arr2[i] > arr1[i]) return false;
    
    return false;
}

bool equality(char *arr1, int al, char *arr2, int bl) // равно
{
    int i;
    if (al != bl) return false;
    else
      for (i=0; i<al; i++)
        if (arr1[i] != arr2[i]) return false;
    
    return true;
}

void pervl(char *arr1, int al, char *arr2, int bl, char *ost, int &cl)// первое вычитаемое для деления
{
    int i;
    if (larger(arr2,bl,arr1,al)) {
       for (i = 0; i < al; i++)
         ost[i] = arr1[i];
       cl = al;
      } else {
    for (i = 0; i < bl; i++) 
      ost[i] = arr1[i];
    cl = bl;
    if (larger(arr2,bl,ost,cl)) {
      ost[cl] = arr1[cl];
      cl++;
      }
    }
}

void subtraction(char *arr1, int &n, char *arr2, int &m) // разность 2 чисел, возвращаем результат в первом
{
    char c[999];
    int i,j,k;
    //добавляем нули
    if (n > m) nullll(arr2,m,n);
    else
      if (n < m) nullll(arr1,n,m);
           //обнуляем резултат
    for (i = 0; i < n; i++)
      c[i] = 0;
           //вычитание
    k = 0;
    for (j = n - 1; j >= 0; j--) {
      c[j] += arr1[j] - arr2[j] + k;
 	    k = 0;
      if(c[j] < 0) {
        k = -1;
        c[j] = 10 + c[j];
        }
      }
         //избавляемся от ненужных нулей
    while (c[0] == 0) {
      for (j = 0; j < n - 1; j++)
        c[j] = c[j + 1];
      if (n != 1) n--; 
      else break;
      }
    while (arr2[0] == 0) {
      for (j = 0; j < m - 1; j++)
        arr2[j] = arr2[j + 1];
      if (m != 1) m--;
      else break;
      }
          //переприсваивание
    for (i = 0; i < n; i++)
      arr1[i] = c[i];
}
void division(char *arr1,  int al,char *arr2, int bl, char *ost, int &cl,char *rez, int &dl)//деление 2 чисел, остаток передается в массив ost,а частное в массив rez
{
    char del[999];
    int el; 
    int i,j,start;
    dl = 0;
    rez[0] = 0;  // если делим на большее число
    pervl(arr1,al,arr2,bl,ost,cl);//определяем первую цифру
    for (i = 0; i < bl; i++)
    del[i] = arr2[i];
    el = bl;
    start = cl;
    if (!(equality(ost,cl,arr1,al) && larger(arr2,bl,arr1,al))) {
      for (i = 0; larger(ost,cl,del,el) || equality(ost,cl,del,el); i++)
        subtraction(ost,cl,del,el);
      rez[dl] = i;
      }
    dl++;
    // определяем другие цифры
    for (i=start; i<al; i++) {
      ost[cl] = arr1[i]; cl++;
      while(ost[0] == 0) {
        for(j = 0; j < cl - 1; j++)
        ost[j] = ost[j + 1];
        if(cl != 1) cl--; 
        else break;
        }
      for (j = 0; larger(ost,cl,del,el) || equality(ost,cl,del,el); j++)
      subtraction(ost,cl,del,el);
      rez[dl] = j; dl++;
      }  
}