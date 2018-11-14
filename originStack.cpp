#include "originStack.h"


OriginStack::OriginStack() : top (-1) {}

bool OriginStack::isEmpty()
{
    return top == -1;
}

bool OriginStack::isFull()
{
    return top == 99;
}

void OriginStack::push(const std::string&e)
{
     if(isFull())
    {
        cout << "Desbordamiento de datos, haciendo un push" << endl;
    }

    data[++top] = e;
}

void OriginStack::pop()
{
    if(isEmpty())
    {
        cout << "Insuficiencia de datos, haciendo pop" << endl;
    }
    data[top--];
    ///return data[top--];
}

std::string OriginStack::getTop()
{
    return data[top];
}
