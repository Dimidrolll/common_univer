#include <iostream>
#include <string>
//#include <stdio.h>
using namespace std;

void main(){
unsigned int k, i, n;
char s[100];
gets(s);
cin >> k;
for (i = 0; s[i] != '\0'; i++)
{
if ( (s[i] != ' ') && (s[i] != '.') && (s[i] != ',') && (s[i] != '-') && (s[i] != ':') ) {
 n = s[i] + 256;
  
 if (n >= 160 && n <= 175 )  if (n + k <= 175) s[i] = (char)(n + k);
                             else s[i] = (char)(224 + ((n + k) % 176));
 if(n >= 224 && n <= 239 )   if (n + k <= 239) s[i] = (char)(n + k);
                             else s[i] = (char)(160 + ((n + k) % 240));
 if(n >= 128 && n <= 159 ) s[i] = (char)(128 + ((n + k - 128) % 33));

}
}


cout << s << endl;
}