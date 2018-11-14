#ifndef PROFESSOR_H_INCLUDED
#define PROFESSOR_H_INCLUDED

#include <string.h>
#include <iostream>
using namespace std;

class Professor {
    private:
        char name[20];
        char code[15];
        char email[30];
        char phone[10];

    public:
        std::string getName();
        std::string getCode();
        std::string getEmail();
        std::string getPhone();

        void setName(const std::string&);
        void setCode(const std::string&);
        void setEmail(const std::string&);
        void setPhone(const std::string&);

        void menuProfessor();
};

#endif // PROFESSOR_H_INCLUDED
