// Учебный проект "Строка Лога"
// Дата: 05 авг 2022

#include <iostream>
#include <string>
#include <stdexcept>

using std::string;
using std::cout;
using std::endl;


int main()
{
    string s = "My string";
    int i = 0;
    while (true) {
        try { cout << s.at(i); }
        catch (std::out_of_range const& e) {
            cout << endl << e.what() << endl;
            break;
        }
        i++;
    }

    
}
