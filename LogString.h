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
		void swap_symbols(int idx1, int idx2);
	public:
		LogString(const string&, short);
		friend std::ostream& operator << (std::ostream&, const LogString&);
		void capitalize();
		void capitalize(int x);
		void capitalize_words();
		void capitalize_words(int z);
		void reverse();
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
		capitalize(0);
	}

	void LogString::capitalize(int x)
	{
		char c = this->at(x);
		short pos = find_symbol_no(c);
		if (pos == -1) return;
		this->at(x) = bigs[pos];
	}

	void LogString::capitalize_words()
	{
		capitalize();
		int n = this->size();
		for (int i = 0; i < n - 2; i++)
			if (this->at(i) == ' ') capitalize(i + 1);
	}

	// Z - фиктивный параметр, определяющий перегруженный
	// вариант метода, использующий find
	void LogString::capitalize_words(int z)
	{
		capitalize();
		int pos;
		int s = this->size();
		int current=0;
		while (true) {
			pos = this->find(' ', current);
			if (pos == -1) break;
			if (pos == s - 1) break;
			capitalize(pos + 1);
			current = pos + 1;
		}
		putchar(7);
	}

	void LogString::swap_symbols(int idx1, int idx2)
	{
		char c = this->at(idx1);
		this->at(idx1) = this->at(idx2);
		this->at(idx2) = c;
	}

	void LogString::reverse()
	{
		int n = size();
		for (int i = 0; i < n / 2; i++) 
			swap_symbols(i, n - i - 1);
	}

}