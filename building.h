#ifndef BUILDING_H_INCLUDED
#define BUILDING_H_INCLUDED

#include "stdio.h"
#include <string.h>
#include <iostream>
using namespace std;

class Building{
private:

    char exists[10];
    char name[10];
    char division[25];
    char id[5];

public:
    ///Vertex();

    void setExists(const std::string& );
    void setName(const std::string& );
    void setDivision(const std::string& );
    void setId(const std::string& );

    std::string getExists();
    std::string getName();
    std::string getDivision();
    std::string getId();
};


#endif // BUILDING_H_INCLUDED
