#include "MethodOldPochmann.h"

MethodOldPochmann::MethodOldPochmann(char up, char front, string scramble) : cubeSolver(up, front, scramble) {};


void MethodOldPochmann::method()
{
    
    side_field buffer;
    cube.orientCube("solve");
    fstream out;
    bool* vertexCorrect = cube.getVertexCorrect();
    bool* edgeCorrect = cube.getEdgeCorrect();
    //out.open(solutionFile, ios::app);
    out.open(cube.getSolutionFilename(), ios::app);
    out.close();
    //vertex
    int edg;
    int vert;
    bool repeat = true;
    while (repeat) {
        repeat = false;
        for (int i = 1; i < 8; i++) {
            if (vertexCorrect[i] == false) { //jezeli jakis wierzcholek jest niepoprawny, szukaj rozwiazania;
                i = 8;
                repeat = true;
            }
        }
        if (repeat == true) {
            vert = searchVertex();
            if (vert < 8)
                solveVertex(vert, 0, true);
        }
    }
    buffer.side = -1;
    buffer.field = -1;
    cube.solutionAppend(buffer);

    //egde
    repeat = true;
    while (repeat) {
        repeat = false;
        for (int i = 1; i < 12; i++) {
            if (edgeCorrect[i] == false) {
                i = 12;
                repeat = true;
            }
        }
        if (repeat == true) {
            edg = searchEdge();
            if (edg < 12)
                solveEdge(edg, 0, true);
        }
        
    }
}
