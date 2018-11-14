#ifndef GRAPHQUEUE_H_INCLUDED
#define GRAPHQUEUE_H_INCLUDED

#include <iostream>
#include <string>
using namespace std;

#define ARRAYSIZE 50

class GraphQueue {
    private:
        std::string data[ARRAYSIZE];
        int frontPos;
        int endPos;

    public:
        GraphQueue();

        bool isEmpty();
        bool isFull();

        void enqueue(const std::string&);

        std::string dequeue();

        std::string getFront();

    };


#endif // GRAPHQUEUE_H_INCLUDED
