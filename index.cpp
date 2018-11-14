#include <string.h>
#include <iostream>
#include "index.h"
using namespace std;

std::string Index::getIndexId()
{
    return indexId;
}

int long Index::getIdxReference()
{
    return idxReference;
}

void Index::setIndexId(const std::string& _indexId)
{
    strcpy(indexId,_indexId.c_str());
}

void Index::setIdxReference(const int long& _idxReference)
{
    idxReference=_idxReference;
}
