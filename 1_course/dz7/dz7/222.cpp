#include <iostream>
//#include <string>
#include <windows.h>
#include <cstdlib>
#include <conio.h>
using namespace std;

/*string rand_input(int n)
{
	
}*/
void main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int amount = 0, i = 0, mode = 0;
	char s1[99];
	gets(s1);
  for ( i = 0; s1[i] != '\0'; ++i) {
    if ((s1[i] == 'À') && (mode == 0)) { 
      ++amount;
      mode = 1;
    }
    if ((s1[i] == ' ') && (mode == 1)) { 
      mode = 0;
    }
  }

  /*char symbolToSearch = 'À';
  for ( i = 0; s1[i] != '\0'; ++i) {
    if (s1[i] == symbolToSearch) {
      symbolToSearch = symbolToSearch == 'À' ?
        ++amount,' ' : 
        'À';
    }*/

 
//next variant
  //char* p;
  //p=s1;

  //do {
  //  p = readWord(p, word);
  //  if (contains(word, 'A')) {
  //    ++amount;
  //  }
  //} while (isEmpty(word));
	


	cout << amount << endl;	
  getch();
}