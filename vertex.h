#ifndef VERTEX_H_INCLUDED
#define VERTEX_H_INCLUDED

#include "stdio.h"
#include <string.h>
#include <iostream>
using namespace std;

class Vertex{
private:

    bool exists;
    char name[10];

public:
    Vertex();

    void setExists(const bool& );
    void setName(const std::string& );

    bool getExists();
    std::string getName();

};



#endif // VERTEX_H_INCLUDED
