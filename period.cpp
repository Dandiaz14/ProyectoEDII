#include "period.h"

string Period::getCode()
{
    return code;
}

string Period::getName()
{
    return name;
}

string Period::getDateBegin()
{
    return dateBegin;
}

string Period::getDateFinish()
{
    return dateFinish;
}

void Period::setCode(const std::string& _code)
{
    strcpy(code,_code.c_str());
}

void Period::setName(const std::string& _name)
{
    strcpy(name,_name.c_str());
}

void Period::setDateBegin(const std::string& _dateBegin)
{
    strcpy(dateBegin,_dateBegin.c_str());
}

void Period::setDateFinish(const std::string& _dateFinish)
{
    strcpy(dateFinish,_dateFinish.c_str());
}

string Period::getStatus()
{
    return status;
}

void Period::setStatus(const std::string& _status)
{
    strcpy(status,_status.c_str());
}
