#include "ListSubject.h"

ListSubject::ListSubject() : anchor(nullptr) { }


/*ListSubject& ListSubject::operator=(const ListSubject& l) {
    deleteAll();

    return *this;
}*/


ListSubject::~ListSubject() {
    deleteAll();
}


bool ListSubject::isEmpty() {
    return anchor == nullptr;
}


void ListSubject::insertData(NodeSubject* p, const NodeSubject& e) {
    if(p != nullptr && !isPosValid(p)) {
        throw ListException("Posicion invalida, insertando.");
    }

    NodeSubject* aux = new NodeSubject(e);
    if(aux == nullptr) {
        throw ListException("Memoria no disponible, insertando.");
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

void ListSubject::doExchange(NodeSubject* x, NodeSubject* y){
    Subject aux(x->getData());
    x->setData(y->getData());
    y->setData(aux);

}


void ListSubject::selectSort()
{
        NodeSubject* i(anchor);
        NodeSubject* j;
        NodeSubject* m;

    while(i != getLastPos())
    {
        m = i;
        j = i->getNext();

        while(j != nullptr)
        {
            if(atoi(j->getData().getCode().c_str()) < atoi(m->getData().getCode().c_str()))
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

void ListSubject::quickSort()
{
    quickSort(getFirstPos(), getLastPos());
}

void ListSubject::quickSort(NodeSubject* leftEdge, NodeSubject* rightEdge)
{
    if(leftEdge == rightEdge)
    {
        return;
    }

    if(leftEdge->getNext() == rightEdge){
         if(leftEdge->getData().getCode() < rightEdge->getData().getCode()){
            doExchange(leftEdge, rightEdge);
         }
         return;
    }


    NodeSubject* i(leftEdge);
    NodeSubject* j(rightEdge);
    while(i != j)
    {
        while(i != j && i->getData().getCode() >= rightEdge->getData().getCode())
        {
            i = i->getNext();
        }
        while(i != j && j->getData().getCode() < rightEdge->getData().getCode())
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



NodeSubject* ListSubject::getFirstPos() {
    return anchor;
}


NodeSubject* ListSubject::getLastPos() {
    if(isEmpty()) {
        return nullptr;
    }
    NodeSubject* aux(anchor);

    while(aux->getNext() != nullptr) {
        aux = aux->getNext();
    }
    return aux;
}


NodeSubject* ListSubject::getPrevPos(NodeSubject* p) {
    if(!isPosValid(p)){
        return nullptr;
    }

    return p->getPrev();
}


NodeSubject* ListSubject::getNextPos(NodeSubject* p) {
    if(!isPosValid(p)) {
        return nullptr;
    }
    return p->getNext();
}

void ListSubject::deleteAll() {
    NodeSubject* aux;

    while(anchor != nullptr) {
        aux = anchor;
        anchor = anchor->getNext();
        delete aux;
    }
}

/// -------------PRICATE METHODS------------------


bool ListSubject::isPosValid(NodeSubject* p) {
    NodeSubject* aux(anchor);
    while(aux != nullptr){
        if(aux == p){
            return true;
        }
        aux = aux->getNext();
    }
    return false;
}

void ListSubject::toString() {
    NodeSubject* aux(anchor);
    char id[15];
    char credit[5];
    char name[30];
    char program[30];
    while (aux != nullptr) {
        ///to_string(id) = aux->getData().getCode();
        strcpy(id,aux->getData().getCode().c_str());
        strcpy(credit,aux->getData().getCredit().c_str());
        strcpy(name,aux->getData().getName().c_str());
        strcpy(program,aux->getData().getProgram().c_str());
        cout<<"Codigo: "<<id << endl <<"Creditos: "<<credit<<endl<<"Nombre: "<<name<<endl<<"Programa: "<< program<<endl<<endl;

        aux = aux->getNext();
    }
}

void ListSubject::FromListToDisk()
{
    NodeSubject* aux = anchor;
    ifstream myFile("Asignaturas.txt", ios::app);
    myFile.close();
    remove("Asignaturas.txt");

    while(aux != nullptr) {

        ofstream writeIndex("Asignaturas.txt", ios::app);
        Subject myAuxData = aux->getData();

        writeIndex.write((char*)&myAuxData,sizeof(Subject));
        writeIndex.close();

        aux = aux->getNext();
        }
}
