#include "profile.h"

string Profile::getName()
{
    return name;
}

string Profile::getCode()
{
    return code;
}

void Profile::setName(const std::string& _name)
{
    strcpy(name,_name.c_str());
}

void Profile::setCode(const std::string& _code)
{
    strcpy(code,_code.c_str());
}
