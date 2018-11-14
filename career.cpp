#include "career.h"

string Career::getName()
{
    return name;
}

int Career::getLabel()
{
    return label;
}

void Career::setName(const std::string& _name)
{
    strcpy(name,_name.c_str());
}

void Career::setLabel(const int& l)
{
    label = l;
}
