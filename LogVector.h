// LogVector class
// Derived from std::vector
// Using element type: LogString
#pragma once
#include <vector>
#include "LogString.h"

namespace top 
{
	// ---------------------------------------------

	enum { COL, LINE };

	class LogVector : public std::vector<LogString>
	{
	public:
		LogVector() : vector<LogString>() {};
		void show(short direction) const;
		void filter(const string&) const;
	};
	// ---------------------------------------------

	// Print array to console window
	void LogVector::show(short direction = COL) const
	{
		int i;
		char delimiter;
		delimiter = (direction == COL)? '\n' : ';';
		for (i = 0; i < this->size(); i++) {
			std::cout << this->at(i);
			std::cout << delimiter;
		}
		std::cout << std::endl;
	}

	void LogVector::filter(const string& f) const
	{
		int i;
		for (i = 0; i < this->size(); i++) {
			if (this->at(i).find(f)	!= -1) {
				std::cout << this->at(i);
				std::cout << std::endl;
			}
		}
		std::cout << std::endl;
	}

}

