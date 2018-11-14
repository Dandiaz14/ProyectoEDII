#include "destinyStack.h"


DestinyStack::DestinyStack() : top (-1) {}

bool DestinyStack::isEmpty()
{
    return top == -1;
}

bool DestinyStack::isFull()
{
    return top == 99;
}

void DestinyStack::push(const std::string&e)
{
     if(isFull())
    {
        cout << "Desbordamiento de datos, haciendo un push" << endl;
    }

    data[++top] = e;
}

void DestinyStack::pop()
{
    if(isEmpty())
    {
        cout << "Insuficiencia de datos, haciendo pop" << endl;
    }
    data[top--];
    ///return data[top--];
}

std::string DestinyStack::getTop()
{
    return data[top];
}
