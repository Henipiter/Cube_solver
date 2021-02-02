#pragma once
#include "cube.h"


using namespace std;
class cubeSolver
{
public:
	cubeSolver(char up, char front, string scramble);
    void scrambleCube(string algorithm); //mieszanie koœci

    int searchVertex(); //wyszukanie nowego wierzcholka do ulozenia
    int searchEdge(); //wyszukanie nowej krawedzi do ulozenia
    void solveVertex(int wall, int flank, bool start); //przemieszczenie wierzcholka na wlasciwe miejsce. Funkcja rekurencyjna
    void solveEdge(int edg, int flank, bool start); //przemieszczenie krawedzi na wlasciwe miejsce. Funkcja rekurencyjna
    //void OldPochmann(); //wywolanie metody ukladania
    virtual void method() = 0;
    void solveCube();
    void showInfo();

protected:
	Cube cube;
};

