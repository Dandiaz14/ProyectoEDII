#include "graphStack.h"

GraphStack::GraphStack() : top (-1) {}

bool GraphStack::isEmpty()
{
    return top == -1;
}

bool GraphStack::isFull()
{
    return top == 9;
}

void GraphStack::push(const std::string&e)
{
     if(isFull())
    {
        cout << "Desbordamiento de datos, haciendo un push" << endl;
    }

    data[++top] = e;
}

std::string GraphStack::pop()
{
    if(isEmpty())
    {
        cout << "Insuficiencia de datos, haciendo pop" << endl;
    }

    return data[top--];
}

std::string GraphStack::getTop()
{
    return data[top];
}
