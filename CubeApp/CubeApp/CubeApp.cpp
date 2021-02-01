#include "cube.h"
#include "cubeSolver.h"
#include "MethodOldPochmann.h"
#include <iostream>
#include <fstream>
using namespace std;
int main() {

	char up, front;
	up = 'y';
	front = 'r';
	
	string scramble = "R' U R";
	

	MethodOldPochmann a(up, front, scramble);
	cubeSolver* b = &a;
	b->method();
	b->solveCube();
	b->showInfo();
	
	//cubeSolver a(up, front, scramble);
	
}
