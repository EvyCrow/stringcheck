#include <iostream>
#include <fstream>
#include <string>
using namespace std;

bool IsTemplate(string str1, string str2)
{
	bool uk = true; 
	int a = str2.size();
	int b = 0;
	int k = 2, kk=a-2;

	if ((str2.size() == 1) and (str2[0] == '*'))
		return 1;

	if ((str2[a-1] == '*') and (str2[a-2] == '*'))
	{
		for (int i = a - 3; i >= 0; i--)
		{
			if (str2[i] == '*')
			{
				kk = i;
				k += 1;
			}
			else break;
		}
		str2.erase(kk + 1, k-1);
		a = str2.size();
	}

	if ((str2.size() == 1) and (str2[0] == '*'))
		return 1;

	for (int i=0; i<=a;i++) //считаем звездочки
	{
		if (str2[i] == '*')
			b += 1;
	}
	if (b == 0)
	{
		b = 1;
		if (str1.size() != str2.size())
			uk = 0;
	}


	int* star = new int [b];
	int s = 0;
	star[0] = a;
	for (int i = 0; i <= a; i++)
	{
		if (str2[i] == '*') //записываем индексы звездочек
		{
			star[s] = i;
			s += 1;
		}
	}


	s = 0;
	string und;
	
	und.append(str2,0,star[0]-1);
	a = und.size();
	for (int i = 0; i <a; i++)
	{
		if ((str1[i] != str2[i]) and (str2[i] != '?'))
		{
			uk = false;
			break;
		}
	}
	
	und.clear();

	und.append(str2,star[b-1]);
	a = und.size();
	for (int i = str2.size()-1; i < star[-1]; i--)
	{
		if ((str1[i] != str2[i]) and (str2[i] != '?'))
		{
			uk = false;
			break;
		}
	}

	und.clear();

	if (b >= 2)
	{
		for (int i = 0; i < b; i++)
		{
			und.append(str2,star[i]+1,star[i+1]);
			bool sus = str1.find(und);
			if (sus == 0)
			{
				uk = 0;
				break;
			}
			und.clear();
		}
	}
	if ((str1.size() == 1) and (str2.size() == 1) and (str1[0] != str2[0]) and (str2[0] != '?'))
		uk = 0;

	if (uk == false) return(false);
	else return(true);

}

int main()
{
	setlocale(LC_ALL, "rus");

	int ck = 1;
	while (ck == 1)
	{
		cout << "Введите 1 для работы программы, 0 для выхода >";
		cin >> ck;
		switch (ck)
		{
			case (0):
				break;


			case(1):
			{
				string str1; string str2;
				cout << "Введите проверяемую строку >";
				cin.ignore(1, '\n');
				getline(cin, str1);
				cout << "Введите шаблон (? = любой символ, * = любой набор символов) >";
				getline(cin, str2);
				bool a = IsTemplate(str1, str2);
				cout <<endl<< a<<endl<<endl;
				break;
			}
			default:
			{
				cout << "Ошибка ввода" << endl;
				continue;
			}
		}
	}
}

