#include "cube.h"
using namespace std;



Cube::Cube()
{

    center = { 'w', 'y', 'o', 'r', 'g','b' };
    //side = new char*[6];
    for (int i = 0; i < 6; i++) {
        side[i] = new char[8];
    }
    ofstream solution{ solutionFile };
    setDefaultCube();
    setAlgoritms();

}
Cube::~Cube()
{
    /*delete vertex;
    delete edge;
    delete *side;
    delete center;
    delete orientation, vertexCorrect;*/
}
//move
void Cube::rotate(string direction, int which_side) {
    //clockwise
    int order[8] = { 1,2,3,5,8,7,6,4 };
    char buffer;
    if (direction == "n") {
        buffer = side[which_side][0];
        side[which_side][0] = side[which_side][2];
        side[which_side][2] = side[which_side][7];
        side[which_side][7] = side[which_side][5];
        side[which_side][5] = buffer;
        buffer = side[which_side][1];
        side[which_side][1] = side[which_side][4];
        side[which_side][4] = side[which_side][6];
        side[which_side][6] = side[which_side][3];
        side[which_side][3] = buffer;
    }
    else if (direction == "y") {
        buffer = side[which_side][0];
        side[which_side][0] = side[which_side][5];
        side[which_side][5] = side[which_side][7];
        side[which_side][7] = side[which_side][2];
        side[which_side][2] = buffer;
        buffer = side[which_side][1];
        side[which_side][1] = side[which_side][3];
        side[which_side][3] = side[which_side][6];
        side[which_side][6] = side[which_side][4];
        side[which_side][4] = buffer;
    }
}
void Cube::rotateCenter(int order[4]) {
    char buffer;
    buffer = center[order[0]];
    for (int i = 0; i < 3; i++)
        center[order[i]] = center[order[i + 1]];
    center[order[3]] = buffer;
}
void Cube::moveElementary_2( int sideOrder[4], int field[2][2]) {
    int buffer[3];
    for (int i = 0; i < 2; i++)
        buffer[i] = side[sideOrder[0]][field[0][i]];
    for (int i = 0; i < 2; i++)
        side[sideOrder[0]][field[0][i]] = side[sideOrder[1]][field[1][i]];
    for (int i = 0; i < 2; i++)
        side[sideOrder[1]][field[1][i]] = side[sideOrder[2]][field[0][1 - i]];
    for (int i = 0; i < 2; i++)
        side[sideOrder[2]][field[0][i]] = side[sideOrder[3]][field[1][i]];
    for (int i = 0; i < 2; i++)
        side[sideOrder[3]][field[1][1 - i]] = buffer[i];
}

void Cube::moveElementary_3(int sideOrder[4], int field[2][3])
{
    int buffer[3];
    for (int i = 0; i < 3; i++)
        buffer[i] = side[sideOrder[0]][field[1][i]];
    for (int i = 0; i < 3; i++)
        side[sideOrder[0]][field[1][i]] = side[sideOrder[1]][field[0][i]];
    for (int i = 0; i < 3; i++)
        side[sideOrder[1]][field[0][i]] = side[sideOrder[2]][field[1][2 - i]];
    for (int i = 0; i < 3; i++)
        side[sideOrder[2]][field[1][i]] = side[sideOrder[3]][field[0][i]];
    for (int i = 0; i < 3; i++)
        side[sideOrder[3]][field[0][2 - i]] = buffer[i];

}
void Cube::move(string direction)
{
    char buffer[3] = {};
    if (direction.find('M') != -1) {
        if (direction[1] == '\'') {
            int order[4] = { 0,4,1,5 };
            rotateCenter(order);
            int field[2][2] = { {1,6}, {1,6} };
            int sideOrder[4] = { 0,4,1,5 };
            moveElementary_2(sideOrder, field);
        }
        else if (direction[1] == '2') {
            move("M");
            move("M");
        }
        else {
            int order[4] = { 0,5,1,4 };
            rotateCenter(order);
            int field[2][2] = { {1,6}, {1,6} };
            int sideOrder[4] = { 4,0,5,1 };
            moveElementary_2(sideOrder, field);
        }
    }
    else if (direction.find('S') != -1) {
        if (direction[1] == '\'') {
            int order[4] = { 0,3,1,2 };
            rotateCenter(order);
            int field[2][2] = { {3,4},{6,1} };
            int sideOrder[4] = { 0,3,1,2 };
            moveElementary_2(sideOrder, field);
        }
        else if (direction[1] == '2') {
            move("S");
            move("S");
        }
        else {
            int order[4] = { 3,0,2,1 };
            rotateCenter(order);
            int field[2][2] = { {1,6},{3,4} };
            int sideOrder[4] = { 3,0,2,1 };
            moveElementary_2(sideOrder, field);
        }
    }
    else if (direction.find('E') != -1) {
        if (direction[1] == '\'') {
            int order[4] = { 2,4,3,5 };
            rotateCenter(order);
            int field[2][2] = { { 3,4 }, { 3,4 } };
            int sideOrder[4] = { 2,4,3,5 };
            moveElementary_2(sideOrder, field);
        }
        else if (direction[1] == '2') {
            move("E");
            move("E");
        }
        else {
            int order[4] = { 4,2,5,3 };
            rotateCenter(order);
            int field[2][2] = { { 3,4 }, { 3,4 } };
            int sideOrder[4] = { 4,2,5,3 };
            moveElementary_2(sideOrder, field);
        }
    }
    else if (direction.find('U') != -1) {
        if (direction[1] == '\'') {
            rotate("n", 0);
            int field[2][3] = { {0,1,2}, {0,1,2} };
            int sideOrder[4] = { 4,2,5,3 };
            moveElementary_3(sideOrder, field);
        }
        else if (direction[1] == '2') {
            move("U");
            move("U");
        }
        else {
            rotate("y", 0);
            int field[2][3] = { {0,1,2}, {0,1,2} };
            int sideOrder[4] = { 2,4,3,5 };
            moveElementary_3(sideOrder, field);
        }


    }
    else if (direction.find('D') != -1) {
        if (direction[1] == '\'') {
            rotate("y", 1);
            int field[2][3] = { {5,6,7}, {5,6,7} };
            int sideOrder[4] = { 2,4,3,5 };
            moveElementary_3(sideOrder, field);
        }
        else if (direction[1] == '2') {
            move("D");
            move("D");
        }
        else {
            rotate("n", 1);
            int field[2][3] = { {5,6,7}, {5,6,7} };
            int sideOrder[4] = { 4,2,5,3 };
            moveElementary_3(sideOrder, field);
        }
    }
    else if (direction.find('F') != -1) {
        if (direction[1] == '\'') {
            rotate("n", 4);
            int field[2][3] = { {7,6,5}, {2,4,7} };
            int sideOrder[4] = { 2,0,3,1 };
            moveElementary_3(sideOrder, field);
            
        }
        else if (direction[1] == '2') {
            move("F");
            move("F");
        }
        else {
            rotate("y", 4);
            int sideOrder[4] = { 0,2,1,3 };
            int field[2][3] = { {2,4,7},{7,6,5} };
            moveElementary_3(sideOrder, field);
        }
        //show();
    }
    else if (direction.find('B') != -1) {
        if (direction[1] == '\'') {
            rotate("y", 5);
            int sideOrder[4] = { 0,2,1,3 };
            int field[2][3] = { {5,3,0} ,{0,1,2} };
            moveElementary_3(sideOrder, field);
        }
        else if (direction[1] == '2') {
            move("B");
            move("B");
        }
        else {
            rotate("n", 5);
            int sideOrder[4] = { 2,0,3,1 };
            int field[2][3] = { {0,1,2}, {5,3,0} };
            moveElementary_3(sideOrder, field);
        }
    }
    else if (direction.find('R') != -1) {
        if (direction[1] == '\'') {
            rotate("y", 3);
            int field[2][3] = { {2,4,7}, {2,4,7} };
            int sideOrder[4] = { 4,0,5,1 };
            moveElementary_3(sideOrder, field);
        }
        else if (direction[1] == '2') {
            move("R");
            move("R");
        }
        else {
            rotate("n", 3);
            int field[2][3] = { {2,4,7}, {2,4,7} };
            int sideOrder[4] = { 0,4,1,5 };
            moveElementary_3(sideOrder, field);
        }
    }
    else if (direction.find('L') != -1) {
        if (direction[1] == '\'') {
            rotate("n", 2);
            int field[2][3] = { {0,3,5}, {0,3,5} };
            int sideOrder[4] = { 0,4,1,5 };
            moveElementary_3(sideOrder, field);

        }
        else if (direction[1] == '2') {
            move("L");
            move("L");
        }
        else {
            rotate("y", 2);  int field[2][3] = { {0,3,5}, {0,3,5} };
            int sideOrder[4] = { 4,0,5,1 };
            moveElementary_3(sideOrder, field);
        }
    }
    else if (direction.find('X') != -1) {
        if (direction[1] == '\'') {

            move("R'");
            move("M");
            move("L''");

        }
        else if (direction[1] == '2') {
            move("X");
            move("X");
        }
        else {
            move("R");
            move("M'");
            move("L'");
        }
    }
    else if (direction.find('Y') != -1) {
        if (direction[1] == '\'') {
            move("U'");
            move("E");
            move("D");
        }
        else if (direction[1] == '2') {
            move("Y");
            move("Y");
        }
        else {
            move("U");
            move("E'");
            move("D'");
        }
    }
    else if (direction.find('Z') != -1) {
        if (direction[1] == '\'') {
            move("F'");
            move("S'");
            move("B");
        }
        else  if (direction[1] == '2') {
            move("Z");
            move("Z");
        }
        else {
            move("F");
            move("S");
            move("B'");
        }
    }
    else if (direction.find('r') != -1) {
        if (direction[1] == '\'') {
            move("R'");
            move("M");
        }
        else if (direction[1] == '2') {
            move("R2");
            move("M2");
        }
        else {
            move("R");
            move("M'");
        }
    }
    else if (direction.find('l') != -1) {
        if (direction[1] == '\'') {
            move("L'");
            move("M'");
        }
        else if (direction[1] == '2') {
            move("L2");
            move("M2");
        }
        else {
            move("L");
            move("M");
        }
    }
    else if (direction.find('f') != -1) {
        if (direction[1] == '\'') {
            move("F'");
            move("S'");
        }
        else  if (direction[1] == '2') {
            move("F2");
            move("S2");
        }
        else {
            move("F");
            move("S");
        }
    }
    else if (direction.find('b') != -1) {
        if (direction[1] == '\'') {
            move("B'");
            move("S");
        }
        else if (direction[1] == '2') {
            move("B2");
            move("S2");
        }
        else {
            move("B");
            move("S'");
        }
    }
    else if (direction.find('u') != -1) {
        if (direction[1] == '\'') {
            move("U'");
            move("E");
        }
        else if (direction[1] == '2') {
            move("U2");
            move("E2");
        }
        else {
            move("U");
            move("E'");
        }
    }
    else if (direction.find('d') != -1) {
        if (direction[1] == '\'') {
            move("D'");
            move("E'");
        }
        else if (direction[1] == '2') {
            move("D2");
            move("E2");
        }
        else {
            move("D");
            move("E");
        }
    }
    else {
        cout << "Metoda move():\nRuch nierozpoznany: " << direction;
    }
}

void Cube::make_moves(string algorithm)
{
    string movement;
    while (algorithm.length() > 0) {
        if (algorithm[0] == ' ' || algorithm[0] == ',')
            algorithm.erase(0, 1);
        else {
            movement += algorithm[0];
            if (isdigit(algorithm[1]) || algorithm[1] == '\'') {
                movement += algorithm[1];
                algorithm.erase(0, 1);
            }
            algorithm.erase(0, 1);
            move(movement);
            movement.clear();
        }
    }
}
string Cube::algReverse(string algorithm){
    string movement;
    string newAlg = "";
    while (algorithm.length() > 0) {
        if (algorithm[0] == ' ' || algorithm[0] == ',')
            algorithm.erase(0, 1);
        else {
            movement += algorithm[0];
            if (isdigit(algorithm[1])) {
                movement += algorithm[1];
                algorithm.erase(0, 2);
            }
            else if (algorithm[1] == '\'') {
                algorithm.erase(0, 2);
            }
            else {
                movement += "\'";
                algorithm.erase(0, 1);
            }
            movement += ' ';
            newAlg.insert(0, movement);
            movement.clear();
        }
    }
    return newAlg;
}
string Cube::permutation(char type){
    switch (type) {
    case 'T':
        return "R U R' U' R' F R2 U' R' U' R U R' F'";
    case '7':
        return "L U' R' U L' U2 R U' R' U2 R";
    case 'J':
        return "R U2 R' U' R U2 L' U R' U' L";
    case 'Y':
        return "R U' R' U' R U R' F' R U R' U' R' F R";
    case 'R':
        return "U' L U2 L' U2 L F' L' U' L U L F L2 U2";
    default:
        cout << "Premutacja " << type << " nieznana! \npermutation(char type)\n";
        return "";
    }
}
//init
void Cube::setDefaultCube() {
    for (int i = 0; i < 6; i++) 
        for (int j = 0; j < 8; j++)
            side[i][j] = center[i];   
    for (int i = 0; i < 8; i++)
        vertexCorrect[i] = false;
    for (int i = 0; i < 12; i++)
        edgeCorrect[i] = false;
}
void Cube::setOrientation(char up, char front) {
    orientation[0] = up;
    orientation[1] = front;
}
void Cube::orientCube(string to) {
    if (to == "solve") {
        if (orientation[0] == 'o' || orientation[0] == 'r') {
            move("Z");
        }
        while (center[0] != orientation[0]) {
            move("X");
        }
        while (center[4] != orientation[1]) {
            move("Y");
        }
    }
    else if (to == "scramble") {
        if (center[2] == 'w' || center[2] == 'y') {
            move("Z");
        }
        while (center[0] != 'w') {
            move("X");
        }
        while (center[4] != 'g') {
            move("Y");
        }
    }
}
void Cube::setAlgoritms() {
    fstream setup;
    string buffer;
    setup.open(setupAlgFile, std::ios::in);
    if (setup.good() == true) {
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 3; j++) {
                getline(setup, vertex[i].algorithm[j]);
                vertex[i].algorithm[j].erase(0, 4);
            }
            getline(setup, buffer);
        }
        for (int i = 0; i < 12; i++) {
            for (int j = 0; j < 2; j++) {
                getline(setup, buffer);
                buffer.erase(0, 3);
                if (buffer.length() < 1)
                    edge[i].typeAlg[j] = '0';
                else
                    edge[i].typeAlg[j] = buffer.front();
                buffer.erase(0, 1);
                edge[i].algorithm[j] = buffer;
            }
            getline(setup, buffer);
        }
    }
    else cout << "Brak pliku " << setupAlgFile << "!" << endl;
    setup.close();
}
void Cube::getMarks() {
    int vertIndexes[8][6] = { //wall, field, wall, field, etc.
        {0,0,2,0,5,0}, {0,2,3,0,5,2}, {0,7,3,2,4,2}, {0,5,2,2,4,0},
        {1,0,2,5,5,5}, {1,2,3,5,5,7}, {1,7,3,7,4,7}, {1,5,2,7,4,5}
    };
    int edgeIndexes[12][4] = {
        {0,4,3,1}, {0,1,5,1}, {0,3,2,1}, {0,6,4,1},
        {3,4,4,4}, {2,4,4,3}, {2,3,5,3}, {3,3,5,4},
        {1,4,3,6}, {1,1,5,6}, {1,3,2,6}, {1,6,4,6}
    };
    orientCube("solve");
    fstream marks;
    string buffer[3];
    marks.open(marksFile, std::ios::in);
    if (marks.good() == true) {
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 3; j++) {
                marks >> vertex[i].name[j];
                vertex[i].name[j].erase(0, 4);
            }
            for (int j = 0; j < 3; j++) {
                vertex[i].wall[j] = vertIndexes[i][j * 2];
                vertex[i].field[j] = vertIndexes[i][j * 2 + 1];
                vertex[i].color[j] = side[vertex[i].wall[j]][vertex[i].field[j]];
            }
            marks >> buffer[0];
        }
        for (int i = 0; i < 12; i++) {
            for (int j = 0; j < 2; j++) {
                marks >> edge[i].name[j];
                edge[i].name[j].erase(0, 3);
            }
            for (int j = 0; j < 2; j++) {
                edge[i].wall[j] = edgeIndexes[i][2 * j];
                edge[i].field[j] = edgeIndexes[i][2 * j + 1];
                edge[i].color[j] = side[edge[i].wall[j]][edge[i].field[j]];
            }
            marks >> buffer[0];
        }
    }
    else cout << "Brak pliku " << marksFile << "!" << endl;
    marks.close();
}

//solution
void Cube::printSolution() {
    unsigned int i;
    for (i = 0;; i++) {
        if (solution[i].side == -1 ) {
            if(isParity)
                cout << "(parity) ";
            else
                cout << "( ) ";
            break;
        }
        cout << vertex[solution[i].side].name[solution[i].field] << " ";
    }
    for (i++; i < solution.size(); i++) {
        cout << edge[solution[i].side].name[solution[i].field] << " ";
    }
}
void Cube::printSolutionTxt() {
    fstream out;
    out.open(solutionFile, ios::app);
    unsigned int i;
    for (i = 0;; i++) {
        if (solution[i].side == -1) {
            out << "\n----------: ";
            out << "\n Parity: ";
            if (isParity)
                out << permutation('R');
            out << "\n----------: ";
            break;
        }
        out << "\n Setup: " << vertex[solution[i].side].algorithm[solution[i].field];
        out << "\n Perm: " << permutation('Y');
        out << "\n Resetup: " << algReverse(vertex[solution[i].side].algorithm[solution[i].field]);
    }
    for (i++; i < solution.size(); i++) {
        out << "\n Setup: " << edge[solution[i].side].algorithm[solution[i].field];
        out << "\n Perm: " << permutation(edge[solution[i].side].typeAlg[solution[i].field]);
        out << "\n Resetup: " << algReverse(edge[solution[i].side].algorithm[solution[i].field]);
    }
    out << "\nEND";
    out.close();
}
void Cube::solveCube()
{
    unsigned int i;
    for (i = 0;; i++) {

        if (solution[i].side == -1 ) {
            if(isParity)
                make_moves(permutation('R'));
            break;
        }
        make_moves(vertex[solution[i].side].algorithm[solution[i].field]);
        make_moves(permutation('Y'));
        make_moves(algReverse(vertex[solution[i].side].algorithm[solution[i].field]));
    }
    for (i++; i < solution.size(); i++) {
        make_moves(edge[solution[i].side].algorithm[solution[i].field]);
        make_moves(permutation(edge[solution[i].side].typeAlg[solution[i].field]));
        make_moves(algReverse(edge[solution[i].side].algorithm[solution[i].field]));
    }
}
void Cube::show()
{
    cout << endl;
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 8; j++) {
            cout << side[i][j] << " ";
        }
        cout << endl;
    }
}

char** Cube::getSide() {
    return side;
}
vector<char> Cube::getCenter() {
    return center;
}
bool Cube::getIsParity() {
    return isParity;
}
bool* Cube::getVertexCorrect() {
    return vertexCorrect;
}
bool* Cube::getEdgeCorrect() {
    return edgeCorrect;
}
vertexData* Cube::getVertex() {
    return vertex;
}
edgeData* Cube::getEdge() {
    return edge;
}
void Cube::setVertexCorrect(int index, bool value) {
    vertexCorrect[index] = value;
}
void Cube::setEdgeCorrect(int index, bool value) {
    edgeCorrect[index] = value;
}
void Cube::solutionAppend(side_field info) {
    solution.push_back(info);
}
void Cube::changeIsParity() {
    isParity = !isParity;
}
string Cube::getSolutionFilename() {
    return solutionFile;
}