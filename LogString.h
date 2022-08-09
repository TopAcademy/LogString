#pragma once
#include <iostream>
#include <string>
using std::string;

namespace top
{
	enum { ERROR, OK, QUESTION, MAIL };

	class LogString : public string
	{
	private:
		// static members
		static char symbols[4];
		static char smalls[];
		static char bigs[];
	private:
		short log_type;
	protected:
		short find_symbol_no(char c);
	public:
		LogString(const string&, short);
		friend std::ostream& operator << (std::ostream&, const LogString&);
		void capitalize();
	};

	char LogString::symbols[4] = { '-', '+', '?', '@' };
	char LogString::smalls[] = "abcdefghijklmnopqrstuvwxyz";
	char LogString::bigs[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

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


	short LogString::find_symbol_no(char c)
	{
		short x = sizeof(smalls);
		for (int i = 0; i < x; i++)
			if (c == smalls[i]) return i;
		return -1;
	}


	void LogString::capitalize()
	{
		char c = this->at(0);
		short pos = find_symbol_no(c);
		if (pos == -1) return;
		this->at(0) = bigs[pos];
	}


}