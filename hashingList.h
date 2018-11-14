#ifndef HASHINGLIST_H_INCLUDED
#define HASHINGLIST_H_INCLUDED


#include "hashingNode.h"
#include "disponibility.h"

class HashingList{
    private:
        HashingNode* anchor;
        int contRegister;

    public:
        HashingList();
        ~HashingList();

        bool isEmpty();

        void insertData(HashingNode*, const Disponibility&);
        HashingNode* getFirstPos();
        HashingNode* getLastPos();

        void deleteAll();

        HashingNode* returnData(const std::string&);

        void deleteData(std::string&);
        Disponibility retrieve(HashingNode*);
        bool findData(std::string&);
        int getCountRegister();
        Disponibility& operator [](const int&);

    };


#endif // HASHINGLIST_H_INCLUDED
