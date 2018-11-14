#ifndef INVERTDATA_H_INCLUDED
#define INVERTDATA_H_INCLUDED

#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

class InvertData {
    private:
        char code[15];
        int label;
    public:
        string getCode();
        int getLabel();

        void setCode(const string&);
        void setLabel(const int&);

        string toString();
    };


#endif // INVERTDATA_H_INCLUDED
