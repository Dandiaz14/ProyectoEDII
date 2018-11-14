#ifndef NODEINDEX_H_INCLUDED
#define NODEINDEX_H_INCLUDED

#include "index.h"

class NodeIndex {
  private:
    Index data;
    NodeIndex* prev;
    NodeIndex* next;

  public:
    NodeIndex();
    NodeIndex(const Index&);

    Index getData();
    NodeIndex* getPrev();
    NodeIndex* getNext();

    void setData(const Index&);
    void setPrev(NodeIndex*);
    void setNext(NodeIndex*);

};

#endif // NODEINDEX_H_INCLUDED
