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
	top::LogString s1("the user is blocked by system", top::OK);
	s1.capitalize_words(49);
	cout << s1 << endl;
}

