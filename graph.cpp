#include "graph.h"
#include "stdio.h"
using namespace std;

Graph::Graph() : lastVertex (-1), stop(-1), isDirected(false), isWeighted(false){}

bool Graph::getIsDirected()
{
    return isDirected;
}

bool Graph::getIsWeighted()
{
    return isWeighted;
}

void Graph::setIsDirected(const bool& d)
{
    isDirected = d;
}

void Graph::setIsWeighted(const bool& w)
{
    isWeighted = w;
}

int Graph::getFirstPos()
{
    if(isEmpty()){
        return -1;
    }
    return 0;
}

int Graph::getLastPos()
{
    if(isEmpty()){
        return -1;
    }
    return lastVertex;
}


bool Graph::isEmpty()
{
    for(int i(0); i<10; i++){
        if(vertices[i].getExists() == true){
            return false;
        }
    }
    return true;
}

bool Graph::isFull()
{
    for(int i(0); i<10; i++){
        if(vertices[i].getExists() == false){
            return false;
        }
    }
    return true;
}

void Graph::insertVertex(const int& p, const std::string& e)
{

    if(isFull()){
        ///Manejar error...
        cout << "Error esta lleno el arreglo vertex" << endl;
    }
    if(p < -1 or p > lastVertex){
        ///Majenar error...
        cout << " Error pos invalida" << endl;
    }

    int i (lastVertex);
    bool flag = true;

    while(i > p){
        vertices[i + 1] = vertices[i];
        i++;
    }
    vertices[p + 1].setName(e);
    vertices[p + 1].setExists(flag);
    lastVertex++;
    stop++;
}

void Graph::deleteVertex(const std::string& e)
{
    int p(findVertexPos(e));

    if(p == -1){
        ///Error
        return;
    }

        for(int i(0); i <= getLastPos(); i++){
            for(int j(0); j <= getLastPos(); j++){
                aristas[p][j].setWeight(0);
                aristas[p][j].setConection(false);
                aristas[i][p].setConection(false);
                aristas[i][p].setWeight(0);

            }
        }
    if(vertices[p].getExists() == true and vertices[p].getName() == e){
        vertices[p].setExists(false);
        while(p < lastVertex){
            vertices[p] = vertices[p+1];
            p++;
        }
        lastVertex--;
        ///cout << "Vertice Eliminado" << endl;
    }
    else {
        ///cout << "El vertice que quiere eliminar no existe. . ." << endl;
    }
}

void Graph::logicalVertexDelete(const std::string& e)
{
    int p(findVertexPos(e));

    if(p == -1){
        ///Error
        return;
    }

    if(vertices[p].getExists() == true and vertices[p].getName() == e){
        vertices[p].setExists(false);
    }
}

void Graph::logicalVertexActivation(const std::string& e)
{
     int p(findVertexPos(e));

    if(p == -1){
        ///Error
        return;
    }

    if(vertices[p].getExists() == false and vertices[p].getName() == e){
        vertices[p].setExists(true);
    }
}

void Graph::modifyVertex(const std::string& o, const std::string& v)
{
    int p(findVertexPos(o));


    vertices[p].setName(v);
}


Vertex Graph::findVertex(const std::string& e)
{
    Vertex aux;
    for(int i(0); i <= lastVertex; i++){
        if(vertices[i].getName() == e){
            aux = vertices[i];
            return aux;
        }
    }
    return aux;
}

int Graph::findVertexPos(const std::string& e)
{
    int aux = 0;
    for(int i(0); i <= lastVertex; i++){
        if(vertices[i].getName() == e){
            aux = i;
            return aux;
        }
    }
    return aux;
}


void Graph::insertEdge(const std::string& o, const std::string& d, const int& w)
{
    if(isEmpty()){
        std::cout << "Esta vacio" << std::endl;
        return;
    }

    Vertex origen;
    Vertex destino;

    origen = findVertex(o);
    destino = findVertex(d);

    if(origen.getExists() == false or destino.getExists() == false){
        cout << "Vertices invalidos" << endl;
    }

    else{
        int origenPos = findVertexPos(o);
        int destinoPos = findVertexPos(d);

        aristas[origenPos][destinoPos].setConection(true);
        aristas[origenPos][destinoPos].setWeight(w);

        if(getIsDirected() == false){
            aristas[origenPos][destinoPos].setConection(true);
            aristas[origenPos][destinoPos].setWeight(w);
        }
        cout << "Conexion Establecida!" << endl;
    }
}

void Graph::deleteEdge(const std::string& o, const std::string& d)
{
    int orig(findVertexPos(o)), dest(findVertexPos(d));

    if(orig == -1 or dest == -1 or aristas[orig][dest].getConection()== false){
        //Error
        cout << "La Arista que quiere eliminar no existe. . ." << endl;
        return;
    }

    if(aristas[orig][dest].getConection() == true){
        aristas[orig][dest].setConection(false);
        aristas[orig][dest].setWeight(0);

        if(getIsDirected() == false){
            aristas[dest][orig].setConection(false);
            aristas[dest][orig].setWeight(0);
        }
        cout << "Arista Eliminada" << endl;
    }
    else {
        cout << "La Arista que quiere eliminar no existe. . ." << endl;
    }

}

void Graph::logicalEdgeDelete(const std::string& o, const std::string& d)
{
    int orig(findVertexPos(o)), dest(findVertexPos(d));

    if(orig == -1 or dest == -1 or aristas[orig][dest].getConection()== false){
        //Error
        cout << "La Arista Que Quiere Dar De Baja NO Existe. . ." << endl;
        return;
    }

    if(aristas[orig][dest].getConection() == true){
        aristas[orig][dest].setConection(false);
        ///aristas[orig][dest].setWeight(0);

        if(getIsDirected() == false){
            aristas[dest][orig].setConection(false);
            ///aristas[dest][orig].setWeight(0);
        }
        cout << "Arista Inactiva!" << endl;
    }
    else {
        cout << "La Arista que quiere eliminar no existe. . ." << endl;
    }

}

void Graph::logicalEdgeActivation(const std::string& o, const std::string& d)
{
    int orig(findVertexPos(o)), dest(findVertexPos(d));

    /*if(orig == -1 or dest == -1 or aristas[orig][dest].getConection()== false){
        //Error
        cout << "La Arista NO Existe. . ." << endl;
        return;
    }*/

    if(aristas[orig][dest].getConection() == false){
        aristas[orig][dest].setConection(true);
        ///aristas[orig][dest].setWeight(0);

        if(getIsDirected() == false){
            aristas[dest][orig].setConection(true);
            ///aristas[dest][orig].setWeight(0);
        }
        cout << "Arista Activa!" << endl;
    }
    else {
        cout << "La Arista NO Existe. . ." << endl;
    }
}


void Graph::modifyEdge(const std::string& o, const std::string& d, const int& n)
{

    int origenPos = findVertexPos(o);
    int destinoPos = findVertexPos(d);

    ///aristas[origenPos][destinoPos].setConection(true);
    aristas[origenPos][destinoPos].setWeight(n);

    if(getIsDirected() == false){
        ///aristas[origenPos][destinoPos].setConection(true);
        aristas[destinoPos][origenPos].setWeight(n);
    }
}


bool Graph::existsEdge(const std::string& o, const std::string& d)
{
    int orig(findVertexPos(o)), dest(findVertexPos(d));

    return orig != -1 and dest != -1 and aristas[orig][dest].getConection();
}


void Graph::toString()
{
    int flag;
    ///int p;

    cout << "Matriz de Vertices:" << endl << endl;

    for(int i(0); i <= getLastPos(); i++){
        if(vertices[i].getExists() == true){
            cout << "    |  " << vertices[i].getName();
        }
    }
    cout << "   |   ";
    cout << endl << endl;

    cout << "Matriz de Adyacencia:" << endl;
     for(int i(0); i <= getLastPos(); i++){
        if(vertices[i].getExists() == true){
            cout << vertices[i].getName();
        }
        for(int j(0); j < getLastPos()+1; j++){
                flag=0;
            if(vertices[i].getExists() == true and vertices[j].getExists() == true){
                ///cout << "   |   " << aristas[i][j].getWeight();
                if(aristas[i][j].getConection() == true){
                    cout << "   |   " << aristas[i][j].getWeight();
                }
                else{
                    cout << "   |   " << "0";
                }
                flag=1;
            }
        }
        if(flag == 1){
            cout << "   |" << endl;
        }
    }
}

void Graph::writeToDiskV()
{
    remove ("Vertices.txt");

    ofstream archivo("Vertices.txt",ios::app);
    if(!archivo.good()){
        cout << "Error";
    }
    else{
         for(int i(0); i <= lastVertex; i++){
            if(vertices[i].getExists() == true){
                archivo << vertices[i].getName() << '|';
            }
         }

    }

    archivo.close();

}

void Graph::readFromDiskV()
{
    lastVertex = -1;
    std::string myStr;
    char myChar[10];

    ifstream archivo;
    archivo.open("Vertices.txt",ios::in);

    if(!archivo.good()){
        cout << "Error";
    }
    else{
        while(!archivo.eof()){
           archivo.getline(myChar,10,'|');

           if(archivo.eof())break;

           myStr = myChar;
           insertVertex(getLastPos(),myStr);
        }
    }
    archivo.close();
}

void Graph::writeToDiskPD()
{
    remove ("Especificaciones.txt");
    ofstream archivo("Especificaciones.txt",ios::app);
    if(!archivo.good()){
        cout << "Error";
    }
    else{

        archivo << getIsWeighted() << '|' << getIsDirected();
    }
    archivo.close();
}

void Graph::readFromDiskPD()
{

    ifstream archivo;
    archivo.open("Especificaciones.txt");
    archivo.seekg(ios::beg);

    int x = 0;
    int y = 0;
    ///char a;

    archivo >> x;
    archivo >> y;

    setIsDirected(x);
    setIsWeighted(y);

    archivo.close();
}


void Graph::writeToDiskA()
{
    remove("Aristas.txt");
    ofstream archivo("Aristas.txt",ios::app);
    if(!archivo.good()){
        cout << "Error";
    }
    else{
         for(int i(0); i <= lastVertex; i++){
            for(int j(0); j <= lastVertex; j++){
                ///if(aristas[i][j].getConection() == true){
                    archivo << aristas[i][j].getWeight() << '|';
                ///}
            }
         }

    }

    archivo.close();

}

void Graph::readFromDiskA()
{
    int x;
    char a;
    ifstream archivo;
    archivo.open("Aristas.txt");
    archivo.seekg(ios::beg);

    x = 0;

   for(int i(0); i <= lastVertex; i++){
        for(int j(0); j<= lastVertex; j++){
            archivo >> x;
            archivo >> a;
            aristas[i][j].setWeight(x);
            if( x >= 1){
                aristas[i][j].setConection(true);
            }
        }
   }
    archivo.close();
}

/*void Graph::deleteAll()
{
    lastVertex == -1;
}*/


void Graph::parseInBreath(const std::string& o)
{
    GraphList visited;
    GraphQueue myQueue;
    int orig(findVertexPos(o));
    if(orig == -1){
        ///Hacerla de pedo
        cout << "Origen invalido" << endl;
    }
    else{

        if(vertices[orig].getExists() == true and vertices[orig].getName() == o){
             cout<<"\nRecorrido En Anchura"<<endl;
            std::string currentVert;

            myQueue.enqueue(vertices[orig].getName()); ///Se encola el vetice origen
            while(!myQueue.isEmpty()){///Mientras la cola no se vacie
                currentVert = myQueue.dequeue();///Se desencola el vertice actual

                if(visited.findData(currentVert) == false){ /// si el vertice actual no ha sido visitado

                   cout << currentVert << " -> "; ///Se "Procesa"
                   visited.insertData(visited.getLastPos(), currentVert);///Se coloca entere los visitados

                   for(int i(0); i<=getLastPos(); i++){///Trabajamos con los destinos del vertice actual
                    if(existsEdge(currentVert,vertices[i].getName()) && visited.findData(vertices[i].getName()) == false){
                        myQueue.enqueue(vertices[i].getName());
                    }
                   }
                }
            }
            cout << endl;
        }
        else{
                cout << "El vertice que ingreso no existe. . . " << endl;
        }
    }
    ///visited.toString();
}

void Graph::parseInDepth(const std::string& o)
{
    GraphList visited;
    GraphStack myStack;
    int orig(findVertexPos(o));
    if(orig == -1){
        ///Hacerla de pedo
        cout << "Origen invalido" << endl;
    }
    else{

        if(vertices[orig].getExists() == true and vertices[orig].getName() == o){
             cout<<"\nRecorrido En Profundidad"<<endl;
            std::string currentVert;

            myStack.push(vertices[orig].getName()); ///Se encola el vetice origen
            while(!myStack.isEmpty()){///Mientras la cola no se vacie
                currentVert = myStack.pop();///Se desencola el vertice actual

                if(visited.findData(currentVert) == false){ /// si el vertice actual no ha sido visitado

                   cout << currentVert << " -> "; ///Se "Procesa"
                   visited.insertData(visited.getLastPos(), currentVert);///Se coloca entere los visitados

                   for(int i(0); i<=getLastPos(); i++){///Trabajamos con los destinos del vertice actual
                    if(existsEdge(currentVert,vertices[i].getName()) && visited.findData(vertices[i].getName()) == false){
                        myStack.push(vertices[i].getName());
                    }
                   }
                }
            }
            cout << endl;
        }
        else{
                cout << "El vertice que ingreso no existe. . . " << endl;
        }
    }
}


void Graph::routeInBreath(const std::string& o, const std::string& d)
{
    GraphList visited;
    GraphQueue myQueue;
    OriginStack myOrigin;
    DestinyStack myDestiny;

    int orig(findVertexPos(o));
    int dest(findVertexPos(d));
    if(orig == -1 or dest == -1){
        ///Hacerla de pedo
        cout << "Origen invalido" << endl;
    }
    else{
        if(vertices[orig].getExists() == true and vertices[dest].getExists() == true and vertices[orig].getName() == o and vertices[dest].getName() == d){
             cout<<"\nRuta En Anchura"<<endl;
            std::string currentVert;

            myQueue.enqueue(vertices[orig].getName()); ///Se encola el vetice origen
            while(!myQueue.isEmpty()){///Mientras la cola no se vacie
                currentVert = myQueue.dequeue();///Se desencola el vertice actual

                if(visited.findData(currentVert) == false){ /// si el vertice actual no ha sido visitado
                    if(currentVert == vertices[dest].getName()){
                        ///Se "Procesa"
                        proccess(myOrigin, myDestiny, vertices[dest].getName());
                        return;
                    }
                    else{
                       visited.insertData(visited.getLastPos(), currentVert);///Se coloca entere los visitados

                       for(int i(0); i<=getLastPos(); i++){///Trabajamos con los destinos del vertice actual
                        if(existsEdge(currentVert,vertices[i].getName()) && visited.findData(vertices[i].getName()) == false){
                            myQueue.enqueue(vertices[i].getName());
                            myOrigin.push(currentVert);
                            myDestiny.push(vertices[i].getName());
                        }
                       }
                    }
                }
            }
            cout << endl;
        }
        else{
                cout << "No Existe Ruta. . . " << endl;
        }
    }

}


void Graph::routeInDepth(const std::string& o, const std::string& d)
{
    GraphList visited;
    GraphStack myStack;
    OriginStack myOrigin;
    DestinyStack myDestiny;

    int orig(findVertexPos(o));
    int dest(findVertexPos(d));
    if(orig == -1 or dest == -1){
        ///Hacerla de pedo
        cout << "Origen invalido" << endl;
    }
    else{
        if(vertices[orig].getExists() == true and vertices[dest].getExists() == true and vertices[orig].getName() == o and vertices[dest].getName() == d){
             cout<<"\nRuta En Profundidad"<<endl;
            std::string currentVert;

            myStack.push(vertices[orig].getName()); ///Se encola el vetice origen
            while(!myStack.isEmpty()){///Mientras la cola no se vacie
                currentVert = myStack.pop();///Se desencola el vertice actual

                if(visited.findData(currentVert) == false){ /// si el vertice actual no ha sido visitado
                    if(currentVert == vertices[dest].getName()){
                        ///Se "Procesa"
                        proccess(myOrigin, myDestiny, vertices[dest].getName());
                        return;
                    }
                    else{
                       visited.insertData(visited.getLastPos(), currentVert);///Se coloca entere los visitados

                       for(int i(0); i<=getLastPos(); i++){///Trabajamos con los destinos del vertice actual
                        if(existsEdge(currentVert,vertices[i].getName()) && visited.findData(vertices[i].getName()) == false){
                            myStack.push(vertices[i].getName());
                            myOrigin.push(currentVert);
                            myDestiny.push(vertices[i].getName());
                        }
                       }
                    }
                }
            }
            cout << endl;
        }
        else{
                cout << "No Existe Ruta. . . " << endl;
        }
    }
}



void Graph::proccess(OriginStack& myOrigin, DestinyStack& myDestiny, const std::string& d)
{
    std::string currentVert;
    currentVert = d;

    while(!myOrigin.isEmpty() and !myDestiny.isEmpty()){
        cout << currentVert << "-";

        while(!myDestiny.isEmpty() and currentVert != myDestiny.getTop()){
            myOrigin.pop();
            myDestiny.pop();
        }
        if(!myOrigin.isEmpty()){
            currentVert = myOrigin.getTop();
        }
        /*else{
            cout << "No hay ruta. . ." << endl;
        }*/
    }
    cout << endl;

}
