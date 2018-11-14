#include "graphList.h"

GraphList::GraphList() : last(-1) {}

bool GraphList::isEmpty()
{
    return last == -1;
}

bool GraphList::isFull()
{
    return last == ARRAYSIZE;
}

void GraphList::insertData(const int&p, const std::string&e)
{
    if(isFull())
  {
    cout << "Desbordamiento de datos, tratando de insertar" << endl;
  }
  if(p < -1 || p > last)
  {
    cout << "Posicion invalida,tratando de insertar" << endl;
  }
  int i(last);

  while (i>p)
  {
      data[i + 1] = data[i];

      i--;
  }

  data[p+1]=e;
  last++;
}

void GraphList::deleteData(const int& p)
{
    if(isEmpty())
    {
       cout << "Insuficiencia de datos, tratando de eliminar"<<endl;
    }
    if (p <0 || p> last)
    {
        cout << "Posicion invalida, tratando de eliminar" << endl;
    }
    int i(p);
    while(i<last)
    {
        data[i] = data[i+1];

        i++;
    }
    last--;
}

int GraphList::getFirstPos()
{
    if(isEmpty())
    {
        return -1;
    }
    return 0;
}

int GraphList::getLastPos()
{
     if(isEmpty())
    {
        return -1;
    }
    return last;
}

int GraphList::getPrevPos(const int&p)
{
    if(isEmpty() || p < 1 || p > last)
    {
        return - 1;
    }
    return p - 1;
}

int GraphList::getNextPos(const int& p)
{
    if(isEmpty() || p < 0 || p > last - 1)
    {
        return -1;
    }
    return p + 1;
}

bool GraphList::findData(const std::string&e)
{
    int i(0);
    while(i<=last)
    {
        if(data[i]== e)
        {
            return true;
        }
        i++;
    }
    return false;
}

/*void List::toString()
{
    for(int i;i<ARRAYSIZE;i++){
        cout << data[i] << "-> ";
    }
}*/
