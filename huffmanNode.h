#ifndef HUFFMANNODE_H_INCLUDED
#define HUFFMANNODE_H_INCLUDED
#include <string>
#include <string.h>

class HuffmanNode{
    private:
        std::string label;  ///Etiqueta
        int sum;            ///Frecuencia
        HuffmanNode* next;         ///Siguiente
        HuffmanNode* prev;         ///Previo
        HuffmanNode* right;        ///Hoja derecha
        HuffmanNode* left;         ///Hoja izquierda

    public:
        HuffmanNode();                 ///Constructor Base
        HuffmanNode(std::string& );    ///Constructor parametrizado

        /*** setters ***/
        void setLabel(const std::string& );
        void setSum(const int& );
        void setNext(HuffmanNode* );
        void setPrev(HuffmanNode* );
        void setRight(HuffmanNode* );
        void setLeft(HuffmanNode* );

        /*** getters ***/
        std::string getLabel();
        int getSum();
        HuffmanNode* getNext();
        HuffmanNode* getPrev();
        HuffmanNode* getRight();
        HuffmanNode* getLeft();
};



#endif // HUFFMANNODE_H_INCLUDED
