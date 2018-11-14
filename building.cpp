#include "building.h"


void Building::setExists(const std::string& e)
{
    strcpy(exists,e.c_str());
}

void Building::setName(const std::string& n)
{
     strcpy(name,n.c_str());
}

void Building::setDivision(const std::string& _division)
{
    strcpy(division,_division.c_str());
}

void Building::setId(const std::string& _id)
{
    strcpy(id,_id.c_str());
}

std::string Building::getExists()
{
    return exists;
}

std::string Building::getName()
{
    return name;
}

string Building::getDivision()
{
    return division;
}

string Building::getId()
{
    return id;
}


