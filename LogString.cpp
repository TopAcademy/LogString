// Учебный проект "Строка Лога"
// Дата: 05 авг 2022

#include <iostream>
#include <string>
#include <stdexcept>
#include "LogString.h"
#include "LogVector.h"

using std::string;
using std::cout;
using std::endl;


int main()
{
	top::LogVector s;
	s.push_back(top::LogString("request denided", top::ERROR));
	s.push_back(top::LogString("user not found", top::ERROR));
	s.push_back(top::LogString("successful request", top::OK));
	s.push_back(top::LogString("invalid user", top::QUESTION));
	s.filter("user");
	/* Результат:
	[-] user not found
	[?] invalid user
	*/
	s.filter("request");
	/* Результат:
	[-] request denided
	[+] sucessful request
	*/

}

