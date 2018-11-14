#include "ListIndex.h"

ListIndex::ListIndex() : anchor(nullptr) { }


/*ListIndex& ListIndex::operator=(const ListIndex& l) {
    deleteAll();

    return *this;
}*/


ListIndex::~ListIndex() {
    deleteAll();
}


bool ListIndex::isEmpty() {
    return anchor == nullptr;
}

bool ListIndex::isValidPos(NodeIndex* p){
    NodeIndex* aux(anchor);///Aux de tipo apuntador a Node inicializado en anchor
    while(aux!=NULL){///Mientras auxiliar no apunte a NULL
        if(aux == p){///Si aux es igual a p
            return true;///Retorna true
        }
        aux = aux->getNext();///Cambia de posicion el apuntador
    }
    return false;///Si no es true, retorna false
}

void ListIndex::insertData(NodeIndex* p, const NodeIndex& e) {
    if(p != nullptr && !isPosValid(p)) {
        ///throw ListException("Posicion invalida, insertando.");
        cout << "Posicion invalida, insertando.";
    }

    NodeIndex* aux = new NodeIndex(e);
    if(aux == nullptr) {
        ///throw ListException("Memoria no disponible, insertando.");
        cout << "Posicion invalida, insertando.";
    }

    if(p == nullptr) { ///Insertando al principio
        //aux->setPrev = nullptr; ya se inicializa nulo
        if(anchor != nullptr){
            anchor->setPrev(aux);
        }
        anchor = aux;

    } else { ///Insertando en cualquier posicion
        aux->setPrev(p);
        aux->setNext(p->getNext());

        if(p->getNext() != nullptr){
            p->getNext()->setPrev(aux);
        }

        p->setNext(aux);
    }
}

void ListIndex::deleteData(NodeIndex* p){///Recibe posicion a eliminar
    if(!isValidPos(p)){///Si la posicion es invalida
        ///throw ListException("Posicion invalida, tratando de eliminar");///Lanza excepcion
    }

    if(p->getPrev() != NULL){///Si p en su campo getPrev es diferente de Nulo
        p->getPrev()->setNext(p->getNext());///p en su campo getPrev en su campo setNext le mando p en su campo getNext
    }

    else{
        anchor = anchor->getNext();///Cambio de posicion anchor
    }

    delete p; ///elimino p
}

NodeIndex* ListIndex::findData(const std::string& s){///Recibe una string y un entero
    NodeIndex* aux(anchor);///aux de tipo Node

    while(aux != NULL){///REcorre cada elemento de la lista
        if(aux->getData().getIndexId() == s){///Si el elemento actual es igual a s
            return aux;///retorno el elemento actual
        }
        aux = aux ->getNext();///cambio de posicion el aux
    }

    return NULL;///retorno nulo si no se encontro nada en ningun caso
}


void ListIndex::doExchange(NodeIndex* x, NodeIndex* y){
    Index aux(x->getData());
    x->setData(y->getData());
    y->setData(aux);

}


void ListIndex::selectSort()
{
        NodeIndex* i(anchor);
        NodeIndex* j;
        NodeIndex* m;

    while(i != getLastPos())
    {
        m = i;
        j = i->getNext();

        while(j != nullptr)
        {
            if(atoi(j->getData().getIndexId().c_str()) < atoi(m->getData().getIndexId().c_str()))
            {
                m = j;
            }
            j = j->getNext();
        }
        if(i != m)
        {
           /// cout << "Debug:\n";
            doExchange(i, m);
        }

        i = i->getNext();
    }

}

void ListIndex::quickSort()
{
    quickSort(getFirstPos(), getLastPos());
}

void ListIndex::quickSort(NodeIndex* leftEdge, NodeIndex* rightEdge)
{
    if(leftEdge == rightEdge)
    {
        return;
    }

    if(leftEdge->getNext() == rightEdge){
         if(leftEdge->getData().getIndexId() < rightEdge->getData().getIndexId()){
            doExchange(leftEdge, rightEdge);
         }
         return;
    }


    NodeIndex* i(leftEdge);
    NodeIndex* j(rightEdge);
    while(i != j)
    {
        while(i != j && i->getData().getIndexId() >= rightEdge->getData().getIndexId())
        {
            i = i->getNext();
        }
        while(i != j && j->getData().getIndexId() < rightEdge->getData().getIndexId())
        {
            j = j->getPrev();
        }

        if(i != j)
        {
            doExchange(i,j);
        }
    }
    if(i != rightEdge)
    {
        doExchange(i, rightEdge);
    }


    if(i!=leftEdge){
        quickSort(leftEdge, i->getPrev());
    }


    if(i !=rightEdge){
     quickSort(i->getNext(), rightEdge);
    }


}



NodeIndex* ListIndex::getFirstPos() {
    return anchor;
}


NodeIndex* ListIndex::getLastPos() {
    if(isEmpty()) {
        return nullptr;
    }
    NodeIndex* aux(anchor);

    while(aux->getNext() != nullptr) {
        aux = aux->getNext();
    }
    return aux;
}


NodeIndex* ListIndex::getPrevPos(NodeIndex* p) {
    if(!isPosValid(p)){
        return nullptr;
    }

    return p->getPrev();
}


NodeIndex* ListIndex::getNextPos(NodeIndex* p) {
    if(!isPosValid(p)) {
        return nullptr;
    }
    return p->getNext();
}

void ListIndex::deleteAll() {
    NodeIndex* aux;

    while(anchor != nullptr) {
        aux = anchor;
        anchor = anchor->getNext();
        delete aux;
    }
}

/// -------------PRICATE METHODS------------------


bool ListIndex::isPosValid(NodeIndex* p) {
    NodeIndex* aux(anchor);
    while(aux != nullptr){
        if(aux == p){
            return true;
        }
        aux = aux->getNext();
    }
    return false;
}

void ListIndex::toString() {
    NodeIndex* aux(anchor);
    char id[15];
    /*char credit[5];
    char name[30];
    char program[30];*/
    while (aux != nullptr) {
        strcpy(id,aux->getData().getIndexId().c_str());
        ///to_string(id) = aux->getData().getIndexId();
        ///strcpy(credit,aux->getData().getName().c_str());
        ///strcpy(age,aux->getData().getAge().c_str());
        ///cout<<"Id: "<<id<<"   Nombre: "<<nombre<<"   Edad: "<<age<<endl;
        cout << "Id: " << id << endl;

        aux = aux->getNext();
    }
}

void ListIndex::fromListToDisk()
{
    NodeIndex* aux = anchor;
    ifstream myFile("Indices.txt", ios::app);
    myFile.close();
    remove("Indices.txt");

    while(aux != nullptr) {

        ofstream writeIndex("Indices.txt", ios::app);
        Index myAuxData = aux->getData();

        writeIndex.write((char*)&myAuxData,sizeof(Index));
        writeIndex.close();

        aux = aux->getNext();
        }
}
