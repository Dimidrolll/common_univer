#include <iostream>
#include <string>
#include <conio.h>
#include <algorithm>
using namespace std;

void deletE(char *s, int &len, int i)
{
  for (int j = i; j < len - 1;j++){
    s[j] = s[j + 1];
  
  }
  len = len - 1;
}

void reversE(char *s, int i,int n)
{
  
  for (int j = i; j < i + n / 2 ;j++){
    swap(s[j],s[i + n - j + i - 1]);
    
  }
}

void main()
{
  char s[99];
  int i,n,len = 0,k = 1;
  gets(s);
  //cout << s << endl;

  for (i = 0; s[i] != '\0';i++)
    ++len;
  //cout << len << endl;
  //deletE(s,len,3);deletE(s,len,3);
  //cout << len << endl;
  //reversE(s,len - len,len);
  i = 0;
  for (i = 0; i < len; i++){
    while (s[i] == ' ') i++;
    n = 0;

    while ((s[i] != ' ') && (k % 2 == 0) && (i < len)){
      n++;
      i++;
    }
    if (k % 2 == 1){ while ((s[i] != ' ') && (i < len)){
      //cout << i << ' ';
      deletE(s,len,i);
      //i++;
    }
    //i++;
    }
    else reversE(s,i - n ,n );

    k++;
  }
  //cout << 11;
  for (int y = 0; y < len; y++ )
    cout << s[y];
  getch();
}




