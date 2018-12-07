#ifndef HUFFMANLIST_H_INCLUDED
#define HUFFMANLIST_H_INCLUDED
#include "huffmanNode.h"
#include "nodeTree.h"

#include <stdlib.h>
#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <windows.h>

class HuffmanList{
    private:
        HuffmanNode* anchor;
    public:
        HuffmanList();           ///Constructor base
        HuffmanList(const HuffmanList&);///Constructor copia
        ~HuffmanList();          ///Destructor

        bool isEmpty();  ///lista vacia
        bool isValidPos(HuffmanNode*);  ///Posición válida

        void insertData(HuffmanNode*,  std::string&);  ///inserta uno
        void insertRoot(HuffmanNode*, HuffmanNode*, HuffmanNode*, std::string& ,int&);
        void deleteData(HuffmanNode*);  ///elimina uno

        HuffmanNode* getFirstPos();       ///posicion del primer elemento
        HuffmanNode* getLastPos();        ///Posicion del ultimo elemento
        HuffmanNode* getNextPos(HuffmanNode*);   ///Posicion del elemento siguiente
        HuffmanNode* getPrevPos(HuffmanNode*);   ///Posicion del elemento anterior

        bool findData(const std::string&); ///Encuentra dato
        void toString();   ///imprime datos

        void preOrder(HuffmanNode*);
        void toStringTree(HuffmanNode* , int);

        std::string retrieveData(HuffmanNode*);    ///regresa dato pidiendo la posicion
        HuffmanNode* returnHuffmanNode(std::string&);     ///retorna nodo pidiendo etiqueta

        void orderedListAscendent();
        void doExchange(HuffmanNode* ,HuffmanNode* );

        void deleteAll(); ///Elimina todo

        void copyAll(const HuffmanList&);  ///copia lista

        HuffmanList & operator = (const HuffmanList&);  ///Operador de igualdad
};



#endif // HUFFMANLIST_H_INCLUDED
