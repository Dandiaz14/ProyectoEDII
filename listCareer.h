#ifndef LISTCAREER_H_INCLUDED
#define LISTCAREER_H_INCLUDED

#include <iostream>
#include <fstream>

#include "career.h"
#include "careerNode.h"
///#include "listexception.h"

class CareerList {
    private:

        CareerNode* anchor;

        int last = 0;

        bool isValidPos(CareerNode*);
    public:
        CareerList();
        ~CareerList();

        bool isEmpty();

        void InsertData(CareerNode*, const Career&);
        void deleteData(CareerNode*);

        CareerNode* findDataLinear(const string&);

        bool searchDataLinear(const string&);
        int reatriveLabel(const string&);

        CareerNode* getFirstPos();
        CareerNode* getLastPost();
        CareerNode* getPrevPos(CareerNode*);
        CareerNode* getNextPos(CareerNode*);

        int getLast();

        void toString();
        string showCareer(const string&);

        void writeToDisck();

    };


#endif // LISTCAREER_H_INCLUDED
