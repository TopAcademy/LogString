#pragma once
#include <iostream>
#include <string>
using std::string;

enum LogTypes { ERROR, OK, QUESTION, MAIL };

class LogString : public string
{
private:
	// static members
	static char symbols[4];
private:
	short log_type;
public:
	LogString(const string&, short);
	friend std::ostream& operator << (std::ostream&, const LogString&);
};

char LogString::symbols[4] = { '-', '+', '?', '@' };

// Constructor 

LogString::LogString(const string& _s, short _type)
	: string(_s)
{
	this->log_type = _type;
}


std::ostream& operator << (std::ostream& _cons, const LogString& _s)
{
	_cons << '[' << LogString::symbols[_s.log_type]
		  << ']' << ' ' << _s.data();
	return _cons;
}
