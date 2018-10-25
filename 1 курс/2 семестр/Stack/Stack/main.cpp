#include "BoundStack.h"
#include <string.h>
#include <iostream>

using namespace std;
int main(){
	try
	{
		setlocale(LC_ALL, "RUSSIAN");
		BoundStack<char> arr;
		string s;
		cout << "Введите текст"<<'\n';
		cin >> s;
		bool ans = 0;
		for (int i = 0; (s[i] != '\0') && (ans == 0); i++)
		{
			if (s[i] == '[') arr.push(s[i]);
			if (s[i] == '{') arr.push(s[i]);
			if (s[i] == '(') arr.push(s[i]);
			if (s[i] == ']')
			if (arr.pop() != '[') ans = 1;
			if (s[i] == '}')
			if (arr.pop() != '{') ans = 1;
			if (s[i] == ')')
			if (arr.pop() != '(') ans = 1;
		}
		if (arr.isEmpty() == 0)
			cout << "Закрывающих скобок меньше, чем открывающих\n";
		else if (ans == 1)
			cout << "Неверно заданная строка\n";
		else
			cout << "Верно заданная строка\n";
	}
	catch (stackOverflow &)
	{
		cout << "Закрывающих скобок больше, чем открывющих\n";
	}
	system("pause");
}
