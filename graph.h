#ifndef GRAPH_H_INCLUDED
#define GRAPH_H_INCLUDED

#include "vertex.h"
#include "edge.h"
#include <iostream>
#include <fstream>
#include "stdio.h"
#include "graphQueue.h"
#include "graphList.h"
#include "graphStack.h"
#include "originStack.h"
#include "destinyStack.h"

using namespace std;

class Graph{
private:
        Vertex vertices[100];
        Edge aristas[100][100];
        int lastVertex;
        int stop;
        bool isDirected;///Es Dirigido
        bool isWeighted;///Es Ponderado
public:
    Graph();

    bool isEmpty();
    bool isFull();

    int getFirstPos();
    int getLastPos();

    bool getIsDirected();
    bool getIsWeighted();
    void setIsDirected(const bool&);
    void setIsWeighted(const bool&);
    ///void deleteAll();

    void insertEdge(const std::string&, const std::string&, const int& );
    void deleteEdge(const std::string&, const std::string&);
    void logicalEdgeDelete(const std::string&, const std::string&);
    void logicalEdgeActivation(const std::string&, const std::string&);
    void modifyEdge(const std::string&, const std::string&, const int&);
    bool existsEdge(const std::string&, const std::string&);

    void insertVertex(const int& , const std::string&);
    void deleteVertex(const std::string&);
    void logicalVertexDelete(const std::string&);
    void logicalVertexActivation(const std::string&);
    Vertex findVertex(const std::string&);
    int findVertexPos(const std::string&);
    void modifyVertex(const std::string&, const std::string&);

    void toString();

    void writeToDiskV();
    void readFromDiskV();

    void writeToDiskPD();
    void readFromDiskPD();

    void writeToDiskA();
    void readFromDiskA();

    void parseInBreath(const std::string&); ///recorrido en anchura
    void parseInDepth(const std::string&); ///recorrido en profundidad

    void proccess(OriginStack&,DestinyStack&,const std::string&);///proceso
    void routeInBreath(const std::string&,const std::string&); ///ruta en anchura
    void routeInDepth(const std::string&,const std::string&); ///ruta en profundidad
};


#endif // GRAPH_H_INCLUDED
