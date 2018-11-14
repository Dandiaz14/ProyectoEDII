#include "graphQueue.h"

GraphQueue::GraphQueue() : frontPos(0), endPos(ARRAYSIZE-1)  {}

bool GraphQueue::isEmpty()
{
    return((frontPos ==  endPos +1) || (frontPos == 0 && endPos == ARRAYSIZE-1));
}

bool GraphQueue::isFull()
{
     return frontPos == endPos + 2 || (frontPos == 0 && endPos == ARRAYSIZE-2) || (frontPos == 1 && endPos == ARRAYSIZE-1);
}

void GraphQueue::enqueue(const std::string&e)
{
    if(isFull())
    {
        cout << "desbordamiento de datos haciendo enqueue" << endl;
    }


    if (++endPos == ARRAYSIZE )
    {
        endPos = 0;
    }
    data[endPos] = e;
}

std::string GraphQueue::dequeue()
{
    if(isEmpty())
    {
        cout << "insuficiencia de datos, haciendo dequeue" << endl;
    }

    std::string result(data[frontPos]);


    if(++frontPos == ARRAYSIZE)
    {
        frontPos = 0;
    }

    return result;
}

std::string GraphQueue::getFront()
{
    if(isEmpty())
        {
            cout << "insuficiencia de datos, haciendo getFront" << endl;
        }
        return data[frontPos];
}
