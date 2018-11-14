#ifndef CATALOG_H_INCLUDED
#define CATALOG_H_INCLUDED

#include <string.h>
#include <iostream>
using namespace std;

class Catalog {
    private:
        char teacherCode[5];
        char subjectCode[5];
        char grade[10];

    public:
        std::string getTeacherCode();
        std::string getSubjectCode();
        std::string getGrade();

        void setTeacherCode(const std::string&);
        void setSubjectCode(const std::string&);
        void setGrade(const std::string&);

};



#endif // CATALOG_H_INCLUDED
