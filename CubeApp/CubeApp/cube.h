#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;
struct side_field {
    int side;
    int field;
};
struct vertexData
{
    string name[3];
    char color[3];
    int wall[3];
    int field[3];
    string algorithm[3];
};
struct edgeData {
    string name[2];
    char color[2];
    int wall[2];
    int field[2];
    string algorithm[2];
    char typeAlg[2];
};
class Cube {
public:
    Cube();
    ~Cube();
    //moves
    void rotate(string direction, int side); //obrot pol na sciance
    void rotateCenter(int order[4]);
    void moveElementary_2(int sideOrder[4], int field[2][2]); //podfunkcja move
    void moveElementary_3(int sideOrder[4], int field[2][3]); //podfunckja move
    void move(string direction); //wykonanie pojedynczego ruchu
    void make_moves(string algorithm); //wykonanie algorytmu
    string algReverse(string algorithm); //funkcja odwraca algorytm. (cofanie setupow)
    string permutation(char type); //algorytmy permutacji
    //init
    void setDefaultCube();
    void setOrientation(char up, char front); //zapisanie orientacji do mieszania
    void orientCube(string to); //obraca kostkê; solve - do rozwiazania; scramble - do miesznia
    void setAlgoritms(); //zczytanie i zapis setupow z pliku
    void getMarks(); //pobiera oznaczenia kostki
    void scrambleCube(string algorithm); //mieszanie koœci
    //solution
    void printSolution(); //wypisz rozwiazanie
    void printSolutionTxt();  //zczytanie i zapis oznaczen na kosci
    void solveCube(); //wykonanie algorytmu rozwiazujacego. Konsekwencja wywolania jest ulozona kostka
    void show();
    //solve
    /*int searchVertex(); //wyszukanie nowego wierzcholka do ulozenia
    int searchEdge(); //wyszukanie nowej krawedzi do ulozenia
    void solveVertex(int wall, int flank, bool start); //przemieszczenie wierzcholka na wlasciwe miejsce. Funkcja rekurencyjna
    void solveEdge(int edg, int flank, bool start); //przemieszczenie krawedzi na wlasciwe miejsce. Funkcja rekurencyjna
    void OldPochmann(); //wywolanie metody ukladania
    */
    char** getSide() {
        return side;
    }
    vector<char> getCenter() {
        return center;
    }
    bool getIsParity() {
        return isParity;
    }
    bool* getVertexCorrect() {
        return vertexCorrect;
    }
    bool* getEdgeCorrect() {
        return edgeCorrect;
    }
    vertexData* getVertex() {
        return vertex;
    }
    edgeData* getEdge() {
        return edge;
    }
    void setVertexCorrect(int index, bool value) {
        vertexCorrect[index] = value;
    }
    void setEdgeCorrect(int index, bool value) {
        edgeCorrect[index] = value;
    }
    void solutionAppend(side_field info) {
        solution.push_back(info);
    }
    void changeIsParity() {
        isParity = !isParity;
    }
    string getSolutionFilename() {
        return solutionFile;
    }
    
    
private:
    vector<char> center;
    char** side=new char* [6];
    char orientation[2] = { 'w','g' }; 
    bool isParity = false; 
    vector<side_field> solution; //ciag indeksow scian i pol, skladajacych sie na rozwiazanie
    string solutionFile = "solution.txt";
    string marksFile = "oznaczenia.txt";
    string setupAlgFile = "setup.txt";
    vertexData *vertex = new vertexData[8];
    edgeData *edge = new edgeData[12]; 
    bool *vertexCorrect = new bool[8]; //flaga, ktore wierzcholki juz sa ulozone
    bool *edgeCorrect = new bool[12]; //flaga, ktore krawedzie juz sa ulozone
};

