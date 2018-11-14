#ifndef CAREER_H_INCLUDED
#define CAREER_H_INCLUDED

#include <string.h>
#include <iostream>
using namespace std;

class Career {
    private:
        char name[20];
        int label;

    public:
        std::string getName();
        int getLabel();

        void setName(const std::string&);
        void setLabel(const int&);
};

#endif // CAREER_H_INCLUDED
