#include "vertex.h"

Vertex::Vertex()
{
    strcpy(name,"");
    exists = false;
}


void Vertex::setExists(const bool& e)
{
    exists = e;
}

void Vertex::setName(const std::string& n)
{
     strcpy(name,n.c_str());
}

bool Vertex::getExists()
{
    return exists;
}

std::string Vertex::getName()
{
    return name;
}



