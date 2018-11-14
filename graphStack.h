#ifndef GRAPHSTACK_H_INCLUDED
#define GRAPHSTACK_H_INCLUDED

#include <iostream>
#include <string>
using namespace std;

class GraphStack{
private:
    std::string data[10];
    int top;

public:
    GraphStack();

    bool isEmpty();
    bool isFull();

    void push(const std::string&);
    std::string pop();

    std::string getTop();


};


#endif // GRAPHSTACK_H_INCLUDED
