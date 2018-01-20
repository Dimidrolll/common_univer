#include <iostream>
#include <string>
#include <cstdlib>
#include <conio.h>
using namespace std;

/*string rand_input(int n)
{
	
}*/
void main()
{

	int i = 0;
	char s1[99];
  string s = "";
	gets(s1);
	while (s1[i] != '\\') i++;
  if (s1[i + 1] != '\0') {
    ++i;
	  while (s1[i] != '\\' && s1[i] != '\0') {
      s = s + s1[i];
      i++;
    }
      cout << s << endl;
    } else {
	    cout << '\\' << endl;	
    }
  getch();
}