#include "cubeSolver.h"

cubeSolver::cubeSolver(char up, char front, string scramble)
{
    cube.setOrientation(up, front);
    cube.getMarks();
    cube.scrambleCube(scramble);
    
    
}
//solve
int cubeSolver::searchVertex() {
    bool* vertexCorrect = cube.getVertexCorrect();
    vertexData* vertex = cube.getVertex();
    char** side = cube.getSide();
    for (int i = 0; i < 8; i++) {
        if (vertexCorrect[i] == true || (
            side[vertex[i].wall[0]][vertex[i].field[0]] == vertex[i].color[0] &&
            side[vertex[i].wall[1]][vertex[i].field[1]] == vertex[i].color[1])) {
            if (i != 0)
                cube.setVertexCorrect(i, true);
                //vertexCorrect[i] = true;
        }
        else
            return i;
    }
    return 8;
}
int cubeSolver::searchEdge() {

    bool* edgeCorrect = cube.getEdgeCorrect();
    edgeData* edge = cube.getEdge();
    char** side = cube.getSide();
    for (int i = 0; i < 12; i++) {
        if (edgeCorrect[i] == true || side[edge[i].wall[0]][edge[i].field[0]] == edge[i].color[0] &&
            side[edge[i].wall[1]][edge[i].field[1]] == edge[i].color[1]) {
            if (i != 0)
                cube.setEdgeCorrect(i, true);

                //edgeCorrect[i] = true;
        }
        else
            return i;
    }
    return 12;
}
void cubeSolver::solveVertex(int vert, int flank, bool start) {
    side_field buffer;
    int target[2];

    bool* vertexCorrect = cube.getVertexCorrect();
    vertexData* vertex = cube.getVertex();
    char** side = cube.getSide();

    for (int j = 0; j < 8; j++) {
        for (int k = 0; k < 3; k++) {
            if (side[vertex[vert].wall[flank]][vertex[vert].field[flank]] == vertex[j].color[k]) {
                if ((side[vertex[vert].wall[(flank + 1) % 3]][vertex[vert].field[(flank + 1) % 3]] == vertex[j].color[(k + 1) % 3] &&
                    side[vertex[vert].wall[(flank + 2) % 3]][vertex[vert].field[(flank + 2) % 3]] == vertex[j].color[(k + 2) % 3]) ||
                    (side[vertex[vert].wall[(flank + 1) % 3]][vertex[vert].field[(flank + 1) % 3]] == vertex[j].color[(k + 2) % 3] &&
                        side[vertex[vert].wall[(flank + 2) % 3]][vertex[vert].field[(flank + 2) % 3]] == vertex[j].color[(k + 1) % 3])) {
                    target[0] = j;
                    target[1] = k;
                    if (!start)
                        cube.setVertexCorrect(vert, true);
                        //vertexCorrect[vert] = true;
                    //readMark(true, vert, flank);
                    if (vert != 0) {
                        buffer.side = vert;
                        buffer.field = flank;
                        cube.solutionAppend(buffer);
                        //solution.push_back(buffer);
                    }
                    cube.changeIsParity();
                    //isParity = !isParity;
                    k = 3;
                    j = 8;
                }
            }
        }
    }
    if (vertexCorrect[target[0]] == false)
        solveVertex(target[0], target[1], false);

}
void cubeSolver::solveEdge(int edg, int flank, bool start) {
    bool* edgeCorrect = cube.getEdgeCorrect();
    edgeData* edge = cube.getEdge();
    char** side = cube.getSide();

    side_field buffer;
    int target[2] = { 0,0 };
    for (int j = 0; j < 12; j++) {
        for (int k = 0; k < 2; k++) {
            if (side[edge[edg].wall[flank]][edge[edg].field[flank]] == edge[j].color[k] &&
                side[edge[edg].wall[(flank + 1) % 2]][edge[edg].field[(flank + 1) % 2]] == edge[j].color[(k + 1) % 2]) {
                target[0] = j;
                target[1] = k;
                if (!start)
                    cube.setEdgeCorrect(edg, true);
                    //edgeCorrect[edg] = true;
                //readMark(false, edg, flank);
                if (edg != 0) {
                    buffer.side = edg;
                    buffer.field = flank;
                    cube.solutionAppend(buffer);
                    //solution.push_back(buffer);
                }
                k = 2;
                j = 12;
            }
        }
    }
    if (edgeCorrect[target[0]] == false)
        solveEdge(target[0], target[1], false);
}
//void cubeSolver::OldPochmann() {
//    side_field buffer;
//    cube.orientCube("solve");
//    fstream out;
//    bool *vertexCorrect = cube.getVertexCorrect();
//    bool* edgeCorrect = cube.getEdgeCorrect();
//    //out.open(solutionFile, ios::app);
//    out.open(cube.getSolutionFilename(), ios::app);
//    out.close();
//    //vertex
//    int edg;
//    int vert;
//    bool repeat = true;
//    while (repeat) {
//        repeat = false;
//        for (int i = 1; i < 8; i++) {
//            if (vertexCorrect[i] == false) { //jezeli jakis wierzcholek jest niepoprawny, szukaj rozwiazania;
//                i = 8;
//                repeat = true;
//            }
//        }
//        if (repeat == true) {
//            vert = searchVertex();
//            if (vert < 8)
//                solveVertex(vert, 0, true);
//        }
//    }
//    buffer.side = -1;
//    buffer.field = -1;
//    cube.solutionAppend(buffer);
//  
//    //egde
//    repeat = true;
//    while (repeat) {
//        repeat = false;
//        for (int i = 1; i < 12; i++) {
//            if (edgeCorrect[i] == false) {
//                i = 12;
//                repeat = true;
//            }
//        }
//        if (repeat == true) {
//            edg = searchEdge();
//            if (edg < 12)
//                solveEdge(edg, 0, true);
//        }
//    }
//}

void cubeSolver::solveCube()
{
    cube.solveCube();
}

void cubeSolver::showInfo()
{

    cube.printSolution();
    cube.printSolutionTxt();
    cube.show();
}
