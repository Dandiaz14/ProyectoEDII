#include "catalog.h"

string Catalog::getTeacherCode()
{
    return teacherCode;
}

string Catalog::getSubjectCode()
{
    return subjectCode;
}

string Catalog::getGrade()
{
    return grade;
}

void Catalog::setTeacherCode(const std::string& tc)
{
    strcpy(teacherCode,tc.c_str());
}

void Catalog::setSubjectCode(const std::string& sc)
{
    strcpy(subjectCode,sc.c_str());
}

void Catalog::setGrade(const std::string& g)
{
    strcpy(grade,g.c_str());
}

