#include "edge.h"

Edge::Edge()
{
    weight = 0;
    conection = false;
}


void Edge::setConection(const bool& c){
    conection = c;
}

bool Edge::getConection(){
    return conection;
}

void Edge::setWeight(const int& w){
    weight = w;
}

int Edge::getWeight(){
    return weight;
}
