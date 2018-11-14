#include "group.h"

string Group::getCode()
{
    return code;
}

string Group::getName()
{
    return name;
}

string Group::getGrade()
{
    return grade;
}

void Group::setCode(const std::string& _code)
{
    strcpy(code,_code.c_str());
}

void Group::setName(const std::string& _name)
{
    strcpy(name,_name.c_str());
}

string Group::getStatus()
{
    return status;
}

void Group::setStatus(const std::string& _status)
{
    strcpy(status,_status.c_str());
}

void Group::setGrade(const std::string& _grade)
{
    strcpy(grade,_grade.c_str());
}

