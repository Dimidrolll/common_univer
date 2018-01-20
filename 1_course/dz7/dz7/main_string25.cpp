#include <iostream>
#include <string>
using namespace std;

void main()
{
	string s10, s2 = "";
	int n = 0;
	
	cin >> s10;
	
	for (int i = 0; i < s10.size(); i++)
	{
		n = n + s10[i] - '0';
		if (i + 1 != s10.size()) n = n * 10;
	}
	cout << n << endl;
	while (n > 0)
	{
		if (n % 2 == 0) s2 = s2 + '0';
		else s2 = s2 + '1';
		n = n / 2;
	}
	reverse(begin(s2),end(s2));
	cout << s2 << endl;
}