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
	int amount = 0, i = 0;
	char s1[99];
	gets(s1);
	cout << s1 << endl;
	while (s1[i] != '\0') {
	  //if (s1[i] != ' ') {
			if (s1[i] == 'À') {
				amount += 1;
				while ((s1[i] != '\0')) { 
					if (s1[i] != ' ') {
						i++;                            
					} else {
						break;
					}
				}
			//}	
			//if (s1[i] == '\0')
				//break;
		}
		i++;
		if (s1[i] == '\0')
			break;
	}
	cout << amount << endl;	

  ////
	

  getch();
}