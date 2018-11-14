#ifndef INDEX_H_INCLUDED
#define INDEX_H_INCLUDED

#include <string.h>
#include <iostream>
using namespace std;

class Index{
    private:
        char indexId[15];
        long int idxReference;
    public:
        std::string getIndexId();
        int long getIdxReference();

        void setIndexId(const std::string&);
        void setIdxReference(const int long&);
};

#endif // INDEX_H_INCLUDED
