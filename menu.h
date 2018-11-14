#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

#include <string.h>
#include <iostream>
using namespace std;

class Menu{
private:

public:
    int login();
    int verifyLogin(const std::string& , const std::string& );
    void mainMenu();
};


#endif // MENU_H_INCLUDED
