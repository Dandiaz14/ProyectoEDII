#ifndef ORIGINSTACK_H_INCLUDED
#define ORIGINSTACK_H_INCLUDED

#include <iostream>
#include <string>
using namespace std;

class OriginStack{
private:
    std::string data[100];
    int top;

public:
    OriginStack();

    bool isEmpty();
    bool isFull();

    void push(const std::string&);
    void pop();

    std::string getTop();


};


#endif // ORIGINSTACK_H_INCLUDED
