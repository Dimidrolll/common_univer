#include <iostream>
#include <string>
using namespace std;

void multiplication(string str, int str_p) //����� ������������� �������
{
	int ar[51], ar1[51]; //������� ��� �������� ���������� ����������� �������� ���������� � �������
	int i, j, l, len, p, t;
	reverse(str.begin(), str.end()); //�������������� ������� ������
	len = str_p * str.size() + 1; //����������� ��������� ������ ��������������� �������
	for (i = 0; i < len; i++) //�������� �������
	{
		ar1[i] = 0;
		ar[i] = 0;
	}
	for (i = 0; i < str.size(); i++) //������������ ������ � ���� str[(n-1)..0]00..000
		ar1[i] += str[i] - '0';

	for (l = 1; l < str_p; l++) //���������� �������� ���������� � �������
	{
		for (i = 0; i < str.size(); i++) //���������� ������������ �����, ���������� � ar1,
		{                                //������� �� ������ ������, ����� ����� � �.�. ������ str
			for (j = 0; j < len; j++)
			{
				ar[j + i] += ar1[j]*(str[i] - '0');
				p = j + i;
				if (ar[p] > 9)   //���������, �������� ���������� ����� ������. ���� �� ��������, ��
				{                //� ���������� t ������� ���������� ��������, ��������������� �������
					t = ar[p] / 10; //��������� ������� �� ������� �� 10 � ��������� � ��� ����������
					ar[p] %= 10;    //���������� �������� ���������� t
					ar[p + 1] += t;
				}
			}
		}
		for (i = 0; i < len; i++) //�������������� � ar1 ���������� �����
			ar1[i] = ar[i];
		for (i = 0; i < len; i++) //�������� �������������� ������
			ar[i] = 0;
	}
	int fin_len = len;
	i = len - 1;
	while (ar1[i] == 0)
	{
		i--;
		fin_len--;
	}
	for (i = 0; i < fin_len/2; i++)
	{
		j = ar1[i];
		ar1[i] = ar1[fin_len - i - 1];
		ar1[fin_len - i - 1] = j;
	}
	for (i = 0; i < fin_len; i++) //�������������� �������� ������� �������� ������ �� ����������
		str[i] = ar1[i] + '0';
	for (i = 0; i < fin_len; i++) //������� ���������� ���������
		cout << str[i];
	cout << endl;
}

void compare(string str_a, string str_b)
{
	int i = 0;
	if (str_a.length() == str_b.length()) 
	{
		while ((str_a[i] == str_b[i]) && (i < str_a.length() - 1)) 
			i++;
		if (str_a[i] > str_b[i])
			cout << "���������� �����: " << str_a << endl;
		else
			if (str_a[i] == str_b[i])
				cout << "����� �����: " << str_a << "=" << str_b << endl;
			else
				cout << "���������� �����: " << str_b << endl;
	}
	else 
		if (str_a.length() > str_b.length()) cout << "���������� �����: " << str_a << endl;
		else cout << "���������� �����: " << str_b << endl;
}

void main()
{
	setlocale(0, "");
	unsigned int m, n, i, count = 0, count1 = 0;
	bool k = 1;
	string a, b, ca, cb;
	
	cout << "������� ����� : "; cin >> a;
	for (i = 0; i < a.size(); i++)
		if (isdigit(a[i]) == 0) //�������� ����������� ������ �� �������������� �� � �����
			count++; 
	if ((count > 0) || ((a[0] >= '4') && (a[1] >= '0') && (a[2] >= '0') && (a[3] >= '0') //����� �������
&& (a[4] > '0')) || (a[0] == '0') || (a.size() > 5))
	{
		cout << "������� ������������ ������. ��������� ���� ����� (0; 40000]";
		k = 0;
	}
	if (k == 1)
	{
		cout << "������� ������� ����� : "; cin >> m;
		if (m > 10)
		{
			cout << "������� ������������ ������. ��������� ���� ������� ����� [0; 10]";
			k = 0;
		}
	}
	cout << endl;

	cout << "������� ����� : "; cin >> b;
	if (k == 1)
	{
		for (i = 0; i < b.size(); i++)
			if (isdigit(b[i]) == 0) //�������� ����������� ������ �� �������������� �� � �����
				count1++; 
		if ((count1 > 0) || ((b[0] >= '4') && (b[1] >= '0') && (b[2] >= '0') && (b[3] >= '0') //����� �������
&& (b[4] > '0')) || (b[0] == '0') || (b.size() > 5))
		{
			cout << "������� ������������ ������. ��������� ���� ����� (0; 40000]";
			k = 0;
		}
		if (k == 1)
		{
			cout << "������� ������� ����� : "; cin >> n;
			if (n > 10)
			{
				cout << "������� ������������ ������. ��������� ���� ������� ����� [0; 10]";
				k = 0;
			}
		}
	}
	cout << endl;

	if ((m == 0) && (n == 0))
		cout << "����� �����: " << 1 << "= " << 1 << endl;
	else 
		if ((m == 0) && (n >= 1))
		{
			cout << "���������� �����: " << cb << endl; multiplication(b, n);
		}
		else
			if ((m >= 1) && (n == 0))
			{
				cout << "���������� �����: "; multiplication(a, m);
			}
			else
				if ((m >= 1) && (n >= 1))
				{
					multiplication(a, m);
					multiplication(b, n);
					compare(a, b);
				}
}