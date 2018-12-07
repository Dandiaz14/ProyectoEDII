#ifndef SUPERUSER_H_INCLUDED
#define SUPERUSER_H_INCLUDED

#include <string.h>
#include <iostream>
#include <sstream>
#include <bitset>
#include "profile.h"
#include "user.h"
#include "group.h"
#include "period.h"
#include "professor.h"
#include "subject.h"
#include "index.h"
#include "listSubject.h"
#include "listIndex.h"
#include "graph.h"
#include "building.h"
#include "career.h"
#include "invertList.h"
#include "listCareer.h"
#include "invertData.h"
#include "hashingTable.h"
#include "disponibility.h"
#include "catalog.h"
#include "academicoffer.h"
#include "huffmanList.h"
using namespace std;

class SuperUser{
private:
    Profile myProfile;
    User myUser;
    Period myPeriod;
    Group myGroup;
    Professor myTeacher;
    Subject mySubject;
    Index myIndex;
    ListSubject myListSubject;
    ListIndex myListIndex;
    Graph myGraph;
    Vertex myVertex;
    Building myBuilding;
    Career myCareer;
    CareerList myCareerList;
    InvertList myInvertList;
    InvertData myInvert;
    HashingTable myHashing;
    Disponibility myDisponibility;
    Catalog myCatalog;
    AcademicOffer myOffer;
    HuffmanList myHuff;
    HuffmanList myTree;
    std::string original;
    std::string trama;
    std::string cadenaEncrypt;
    int contadores[128];
    int raiz;
    bool isEncrypted = false;
public:
    ///Lanza El Menu Principal
    void adminMenu();

    ///Inserta C/U
    void insertData();
    void insertProfile();
    void insertUser();
    void insertGroup();
    void insertPeriod();
    void insertProfessor();
    void insertSubject();
    void insertVertex();
    void insertEdge();
    void insertHashing();
    void insertCatalog();
    void insertOffer();

    ///Muestra C/U
    void showData();
    void showProfile();
    void showUser();
    void showGroup();
    void showPeriod();
    void showProfessor();
    void showSubject();
    void showDescentSubject();
    void showBuilding();
    void showCareerMenu();
    void showDisponibility();
    void showCatalog();
    void showOffer();

    ///Busca C/U
    void findData();
    void findProfile();
    void findUser();
    void findGroup();
    void findPeriod();
    void findProfessor();
    void findSubject();
    void findBuilding();

    ///Modifica C/U
    void modifyData();
    void modifyProfile();
    void modifyUser();
    void modifyGroup();
    void modifyPeriod();
    void modifyProfessor();
    void modifySubject();
    void modifyBuilding();
    void modifyDisponibility();
    void modifyOffer();

    ///Elimina C/U
    void deleteData();
    void deleteProfile();
    void deleteUser();
    void deleteGroup();
    void deletePeriod();
    void deleteProfessor();
    void deleteSubject();
    void deleteBuilding();
    void deleteEdge();
    void deleteDisponibility();
    void deleteOffer();

    ///Eliminacion Logica
    void logicDelete();
    void logicDeleteGroup();
    void logicDeletePeriod();
    void logicDeleteSubject();
    void logicDeleteBuilding();
    void logicDeleteEdge();

    ///Activacion Logica
    void logicActivation();
    void logicActivationGroup();
    void logicActivationPeriod();
    void logicActivationSubject();
    void logicActivationBuilding();
    void logicActivationEdge();

    ///Auxiliares
    bool existUser(const std::string&);
    bool verifyDelete(const std::string&);
    bool verifyEmail(const std::string&);
    void fromDiskToList();
    void fromListToDisk();
    void selfSaved();
    void graphInsert();
    void graphShowMenu();
    void parse();
    void route();
    void fromDiskToInvertList();
    bool subjectValid(const std::string&);
    bool teacherValid(const std::string&);
    void increaseTable();
    string reatriveTeacher(const std::string&);
    string reatriveSubject(const std::string&);
    int showSpecificSubject(const std::string&,int);///Recibe el nombre y el grupo a mostrar materias y retorna cuantas son
    string reatriveGroup(const std::string&);
    void reatriveOfferGroup(const std::string&,const std::string&);
    void showSpecificOfferSubject(const std::string&,const std::string&);
    void reatriveDisponibility(const std::string&);///Muestra de disponibilidad los maestros que la pueden dar.
    bool verifyTeacher(const std::string&);
    bool verifySubject(const std::string&);
    bool verifyGroup(const std::string&);
    bool verifyPeriod(const std::string&);
    void encrypt();
    void desencrypt();
    void createHuffmanList();
    void createTree();
    void translateEncrypt();
    void packUp();
    void dictionary(HuffmanNode* , std::string& );
    void readDictionary();
    void writeToDiskHuff(std::string& , std::string& );
    void readText();
    void convert();
    void translateDesencrypt();

    ///Incremento ID's
    int increaseUserId();
    void writeToId(const int&);
    int increaseGroupId();
    void writeToGroupId(const int&);
    int increasePeriodId();
    void writeToPeriodId(const int&);
    int increaseSubjectId();
    void writeToSubjectId(const int&);
    int increaseBuildingId();
    void writeToBuildingId(const int&);
    int increaseProfessorId();
    void writeToProfessorId(const int&);
};

#endif // SUPERUSER_H_INCLUDED
