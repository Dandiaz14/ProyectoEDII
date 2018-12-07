#ifndef NODETREE_H_INCLUDED
#define NODETREE_H_INCLUDED

#include <string>
#include <string.h>

class NodeTree{
    private:
        std::string label;  ///Etiqueta
        int sum;            ///Frecuencia
        NodeTree* right;         ///Siguiente
        NodeTree* left;         ///Previo

    public:
        NodeTree();                 ///Constructor Base

        /*** setters ***/
        void setLabel(const std::string& );
        void setSum(const int& );
        void setRight(NodeTree* );
        void setLeft(NodeTree* );

        /*** getters ***/
        std::string getLabel();
        int getSum();
        NodeTree* getRight();
        NodeTree* getLeft();
};


#endif // NODETREE_H_INCLUDED
