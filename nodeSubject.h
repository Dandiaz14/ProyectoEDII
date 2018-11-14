#ifndef NODESUBJECT_H_INCLUDED
#define NODESUBJECT_H_INCLUDED


#include "subject.h"

class NodeSubject {
  private:
    Subject data;
    NodeSubject* prev;
    NodeSubject* next;

  public:
    NodeSubject();
    NodeSubject(const Subject&);

    Subject getData();
    NodeSubject* getPrev();
    NodeSubject* getNext();

    void setData(const Subject&);
    void setPrev(NodeSubject*);
    void setNext(NodeSubject*);

};

#endif // NODESUBJECT_H_INCLUDED
