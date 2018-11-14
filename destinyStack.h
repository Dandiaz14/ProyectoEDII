#ifndef DESTINYSTACK_H_INCLUDED
#define DESTINYSTACK_H_INCLUDED

#include <iostream>
#include <string>
using namespace std;

class DestinyStack{
private:
    std::string data[100];
    int top;

public:
    DestinyStack();

    bool isEmpty();
    bool isFull();

    void push(const std::string&);
    void pop();

    std::string getTop();


};



#endif // DESTINYSTACK_H_INCLUDED
