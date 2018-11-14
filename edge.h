#ifndef EDGE_H_INCLUDED
#define EDGE_H_INCLUDED

class Edge{
private:

    bool conection;
    int weight;

public:
    Edge();
    ///Poner peso
    void setConection(const bool& );
    void setWeight(const int& );

    bool getConection();
    int getWeight();
};



#endif // EDGE_H_INCLUDED
