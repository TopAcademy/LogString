// Учебный проект "Строка Лога"
// Дата: 05 авг 2022

#include <iostream>
#include <string>
#include <stdexcept>
#include "LogString.h"

using std::string;
using std::cout;
using std::endl;


int main()
{
	LogString s1("Illegal user", QUESTION);
	s1 += "!!!";
	cout << s1 << endl;
}

