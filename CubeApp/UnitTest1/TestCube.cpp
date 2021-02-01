
#include "CppUnitTest.h"
#include "../CubeApp/cube.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TestCube
{
	TEST_CLASS(CubeOrient) {
	public:
		TEST_METHOD(orient1) {
			Cube a;
			a.setOrientation('r', 'b');
			a.orientCube("solve");
			vector<char> g = a.getCenter();
			vector<char> c = { 'r','o','y','w','b','g' };
			char** t = new char* [6];
			char** m = a.getSide();
			t[3] = new char[8]{ 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w' };
			t[2] = new char[8]{ 'y', 'y', 'y', 'y', 'y', 'y', 'y', 'y' };
			t[1] = new char[8]{ 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o' };
			t[0] = new char[8]{ 'r', 'r', 'r', 'r', 'r', 'r', 'r', 'r' };
			t[5] = new char[8]{ 'g','g','g','g', 'g','g','g', 'g' };
			t[4] = new char[8]{ 'b','b' ,'b','b','b','b','b','b' };

			for (int i = 0; i < 6; i++) {
				Assert::AreEqual(c[i], g[i]);
				for (int j = 0; j < 8; j++)
					Assert::AreEqual(t[i][j], m[i][j]);
			}
		}
		TEST_METHOD(orient2) {
			Cube a;
			a.setOrientation('b', 'w');
			a.orientCube("solve");
			vector<char> g = a.getCenter();
			vector<char> c = { 'b','g','o','r','w','y' };
			char** t = new char* [6];
			char** m = a.getSide();
			t[4] = new char[8]{ 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w' };
			t[5] = new char[8]{ 'y', 'y', 'y', 'y', 'y', 'y', 'y', 'y' };
			t[2] = new char[8]{ 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o' };
			t[3] = new char[8]{ 'r', 'r', 'r', 'r', 'r', 'r', 'r', 'r' };
			t[1] = new char[8]{ 'g','g','g','g', 'g','g','g', 'g' };
			t[0] = new char[8]{ 'b','b' ,'b','b','b','b','b','b' };

			for (int i = 0; i < 6; i++) {
				Assert::AreEqual(c[i], g[i]);
				for (int j = 0; j < 8; j++)
					Assert::AreEqual(t[i][j], m[i][j]);
			}
		}
		TEST_METHOD(orient3) {
			Cube a;
			a.setOrientation('y', 'r');
			a.orientCube("solve");
			vector<char> g = a.getCenter();
			vector<char> c = { 'y','w','b','g','r','o' };
			char** t = new char* [6];
			char** m = a.getSide();
			t[1] = new char[8]{ 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w' };
			t[0] = new char[8]{ 'y', 'y', 'y', 'y', 'y', 'y', 'y', 'y' };
			t[5] = new char[8]{ 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o' };
			t[4] = new char[8]{ 'r', 'r', 'r', 'r', 'r', 'r', 'r', 'r' };
			t[3] = new char[8]{ 'g','g','g','g', 'g','g','g', 'g' };
			t[2] = new char[8]{ 'b','b' ,'b','b','b','b','b','b' };

			for (int i = 0; i < 6; i++) {
				Assert::AreEqual(c[i], g[i]);
				for (int j = 0; j < 8; j++)
					Assert::AreEqual(t[i][j], m[i][j]);
			}
		}


	};
	TEST_CLASS(CubeSimplyMoves)
	{
	public:
		TEST_METHOD(initCube)
		{
			Cube a;
			vector<char> g = a.getCenter();
			vector<char> c = { 'w','y','o','r','g','b' };
			char** t = new char* [6];
			char** m = a.getSide();
			t[0] = new char[8]{ 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w' };
			t[1] = new char[8]{ 'y', 'y', 'y', 'y', 'y', 'y', 'y', 'y' };
			t[2] = new char[8]{ 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o' };
			t[3] = new char[8]{ 'r', 'r', 'r', 'r', 'r', 'r', 'r', 'r' };
			t[4] = new char[8]{ 'g','g','g','g', 'g','g','g', 'g' };
			t[5] = new char[8]{ 'b','b' ,'b','b','b','b','b','b' };

			for (int i = 0; i < 6; i++) {
				Assert::AreEqual(c[i], g[i]);
				for (int j = 0; j < 8; j++)
					Assert::AreEqual(t[i][j], m[i][j]);
			}
		}
		TEST_METHOD(Move_S)
		{
			Cube a;
			a.move("S");
			vector<char> g = a.getCenter();
			vector<char> c = { 'o','r','y','w','g','b' };
			char** t = new char* [6];
			char** m = a.getSide();
			t[0] = new char[8]{ 'w', 'w', 'w', 'o', 'o', 'w', 'w', 'w' };
			t[1] = new char[8]{ 'y', 'y', 'y', 'r', 'r', 'y', 'y', 'y' };
			t[2] = new char[8]{ 'o', 'y', 'o', 'o', 'o', 'o', 'y', 'o' };
			t[3] = new char[8]{ 'r', 'w', 'r', 'r', 'r', 'r', 'w', 'r' };
			t[4] = new char[8]{ 'g','g','g','g', 'g','g','g', 'g' };
			t[5] = new char[8]{ 'b','b' ,'b','b','b','b','b','b' };

			for (int i = 0; i < 6; i++) {
				Assert::AreEqual(c[i], g[i]);
				for (int j = 0; j < 8; j++)
					Assert::AreEqual(t[i][j], m[i][j]);
			}
		}
		TEST_METHOD(Move_Sprim)
		{
			Cube a;
			a.move("S'");
			vector<char> g = a.getCenter();
			vector<char> c = { 'r','o','w','y','g','b' };
			char** t = new char* [6];
			char** m = a.getSide();
			t[0] = new char[8]{ 'w', 'w', 'w', 'r', 'r', 'w', 'w', 'w' };
			t[1] = new char[8]{ 'y', 'y', 'y', 'o', 'o', 'y', 'y', 'y' };
			t[2] = new char[8]{ 'o', 'w', 'o', 'o', 'o', 'o', 'w', 'o' };
			t[3] = new char[8]{ 'r', 'y', 'r', 'r', 'r', 'r', 'y', 'r' };
			t[4] = new char[8]{ 'g','g','g','g', 'g','g','g', 'g' };
			t[5] = new char[8]{ 'b','b' ,'b','b','b','b','b','b' };

			for (int i = 0; i < 6; i++) {
				Assert::AreEqual(c[i], g[i]);
				for (int j = 0; j < 8; j++)
					Assert::AreEqual(t[i][j], m[i][j]);
			}
		}
		TEST_METHOD(Move_M)
		{
			Cube a;
			a.move("M");
			vector<char> g = a.getCenter();
			vector<char> c = { 'b','g','o','r','w','y' };
			char** t = new char* [6];
			char** m = a.getSide();
			t[0] = new char[8]{ 'w', 'b', 'w', 'w', 'w', 'w', 'b', 'w' };
			t[1] = new char[8]{ 'y', 'g', 'y', 'y', 'y', 'y', 'g', 'y' };
			t[2] = new char[8]{ 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o' };
			t[3] = new char[8]{ 'r', 'r', 'r', 'r', 'r', 'r', 'r', 'r' };
			t[4] = new char[8]{ 'g','w','g','g', 'g','g','w', 'g' };
			t[5] = new char[8]{ 'b','y' ,'b','b','b','b','y','b' };

			for (int i = 0; i < 6; i++) {
				Assert::AreEqual(c[i], g[i]);
				for (int j = 0; j < 8; j++)
					Assert::AreEqual(t[i][j], m[i][j]);
			}
		}
		TEST_METHOD(Move_Mprim)
		{
			Cube a;
			a.move("M'");
			vector<char> g = a.getCenter();
			vector<char> c = { 'g','b','o','r','y','w' };
			char** t = new char* [6];
			char** m = a.getSide();
			t[0] = new char[8]{ 'w', 'g', 'w', 'w', 'w', 'w', 'g', 'w' };
			t[1] = new char[8]{ 'y', 'b', 'y', 'y', 'y', 'y', 'b', 'y' };
			t[2] = new char[8]{ 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o' };
			t[3] = new char[8]{ 'r', 'r', 'r', 'r', 'r', 'r', 'r', 'r' };
			t[4] = new char[8]{ 'g','y','g','g', 'g','g','y', 'g' };
			t[5] = new char[8]{ 'b','w' ,'b','b','b','b','w','b' };

			for (int i = 0; i < 6; i++) {
				Assert::AreEqual(c[i], g[i]);
				for (int j = 0; j < 8; j++)
					Assert::AreEqual(t[i][j], m[i][j]);
			}
		}
		TEST_METHOD(Move_E)
		{
			Cube a;
			a.move("E");
			vector<char> g = a.getCenter();
			vector<char> c = { 'w','y','b','g','o','r' };
			char** t = new char* [6];
			char** m = a.getSide();
			t[0] = new char[8]{ 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w' };
			t[1] = new char[8]{ 'y', 'y', 'y', 'y', 'y', 'y', 'y', 'y' };
			t[2] = new char[8]{ 'o', 'o', 'o', 'b', 'b', 'o', 'o', 'o' };
			t[3] = new char[8]{ 'r', 'r', 'r', 'g', 'g', 'r', 'r', 'r' };
			t[4] = new char[8]{ 'g','g','g','o', 'o','g','g', 'g' };
			t[5] = new char[8]{ 'b','b' ,'b','r','r','b','b','b' };

			for (int i = 0; i < 6; i++) {
				Assert::AreEqual(c[i], g[i]);
				for (int j = 0; j < 8; j++)
					Assert::AreEqual(t[i][j], m[i][j]);
			}
		}
		TEST_METHOD(Move_Eprim)
		{
			Cube a;
			a.move("E'");
			vector<char> g = a.getCenter();
			vector<char> c = { 'w','y','g','b','r','o' };
			char** t = new char* [6];
			char** m = a.getSide();
			t[0] = new char[8]{ 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w' };
			t[1] = new char[8]{ 'y', 'y', 'y', 'y', 'y', 'y', 'y', 'y' };
			t[2] = new char[8]{ 'o', 'o', 'o', 'g', 'g', 'o', 'o', 'o' };
			t[3] = new char[8]{ 'r', 'r', 'r', 'b', 'b', 'r', 'r', 'r' };
			t[4] = new char[8]{ 'g','g','g','r', 'r','g','g', 'g' };
			t[5] = new char[8]{ 'b','b' ,'b','o','o','b','b','b' };

			for (int i = 0; i < 6; i++) {
				Assert::AreEqual(c[i], g[i]);
				for (int j = 0; j < 8; j++)
					Assert::AreEqual(t[i][j], m[i][j]);
			}
		}
		TEST_METHOD(Move_R)
		{
			Cube a;
			a.move("R");
			vector<char> g = a.getCenter();
			vector<char> c = { 'w','y','o','r','g','b' };
			char** t = new char* [6];
			char** m = a.getSide();
			t[0] = new char[8]{ 'w', 'w', 'g', 'w', 'g', 'w', 'w', 'g' };
			t[1] = new char[8]{ 'y', 'y', 'b', 'y', 'b', 'y', 'y', 'b' };
			t[2] = new char[8]{ 'o','o', 'o', 'o', 'o', 'o', 'o', 'o' };
			t[3] = new char[8]{ 'r','r', 'r', 'r', 'r', 'r', 'r', 'r' };
			t[4] = new char[8]{ 'g','g', 'y','g','y','g','g', 'y' };
			t[5] = new char[8]{ 'b','b','w','b','w' ,'b','b','w' };

			for (int i = 0; i < 6; i++) {
				Assert::AreEqual(c[i], g[i]);
				for (int j = 0; j < 8; j++)
					Assert::AreEqual(t[i][j], m[i][j]);
			}
		}
		TEST_METHOD(Move_Rprim)
		{
			Cube a;
			a.move("R'");
			vector<char> g = a.getCenter();
			vector<char> c = { 'w','y','o','r','g','b' };
			char** t = new char* [6];
			char** m = a.getSide();
			t[0] = new char[8]{ 'w', 'w', 'b', 'w', 'b', 'w', 'w', 'b' };
			t[1] = new char[8]{ 'y', 'y', 'g', 'y', 'g', 'y', 'y', 'g' };
			t[2] = new char[8]{ 'o','o', 'o', 'o', 'o', 'o', 'o', 'o' };
			t[3] = new char[8]{ 'r','r', 'r', 'r', 'r', 'r', 'r', 'r' };
			t[4] = new char[8]{ 'g','g', 'w','g','w','g','g', 'w' };
			t[5] = new char[8]{ 'b','b','y','b','y' ,'b','b','y' };

			for (int i = 0; i < 6; i++) {
				Assert::AreEqual(c[i], g[i]);
				for (int j = 0; j < 8; j++)
					Assert::AreEqual(t[i][j], m[i][j]);
			}
		}
		TEST_METHOD(Move_L)
		{
			Cube a;
			a.move("L");
			vector<char> g = a.getCenter();
			vector<char> c = { 'w','y','o','r','g','b' };
			char** t = new char* [6];
			char** m = a.getSide();
			t[0] = new char[8]{ 'b', 'w', 'w', 'b', 'w', 'b', 'w', 'w' };
			t[1] = new char[8]{ 'g', 'y', 'y', 'g', 'y', 'g', 'y', 'y' };
			t[2] = new char[8]{ 'o','o', 'o', 'o', 'o', 'o', 'o', 'o' };
			t[3] = new char[8]{ 'r','r', 'r', 'r', 'r', 'r', 'r', 'r' };
			t[4] = new char[8]{ 'w','g', 'g','w','g','w','g', 'g' };
			t[5] = new char[8]{ 'y','b','b','y','b' ,'y','b','b' };

			for (int i = 0; i < 6; i++) {
				Assert::AreEqual(c[i], g[i]);
				for (int j = 0; j < 8; j++)
					Assert::AreEqual(t[i][j], m[i][j]);
			}
		}
		TEST_METHOD(Move_Lprim)
		{
			Cube a;
			a.move("L'");
			vector<char> g = a.getCenter();
			vector<char> c = { 'w','y','o','r','g','b' };
			char** t = new char* [6];
			char** m = a.getSide();
			t[0] = new char[8]{ 'g', 'w', 'w', 'g', 'w', 'g', 'w', 'w' };
			t[1] = new char[8]{ 'b', 'y', 'y', 'b', 'y', 'b', 'y', 'y' };
			t[2] = new char[8]{ 'o','o', 'o', 'o', 'o', 'o', 'o', 'o' };
			t[3] = new char[8]{ 'r','r', 'r', 'r', 'r', 'r', 'r', 'r' };
			t[4] = new char[8]{ 'y','g', 'g','y','g','y','g', 'g' };
			t[5] = new char[8]{ 'w','b','b','w','b' ,'w','b','b' };

			for (int i = 0; i < 6; i++) {
				Assert::AreEqual(c[i], g[i]);
				for (int j = 0; j < 8; j++)
					Assert::AreEqual(t[i][j], m[i][j]);
			}
		}
		TEST_METHOD(Move_U)
		{
			Cube a;
			a.move("U");
			vector<char> g = a.getCenter();
			vector<char> c = { 'w','y','o','r','g','b' };
			char** t = new char* [6];
			char** m = a.getSide();
			t[0] = new char[8]{ 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w' };
			t[1] = new char[8]{ 'y', 'y', 'y', 'y', 'y', 'y', 'y', 'y' };
			t[2] = new char[8]{ 'g','g', 'g', 'o', 'o', 'o', 'o', 'o' };
			t[3] = new char[8]{ 'b','b', 'b', 'r', 'r', 'r', 'r', 'r' };
			t[4] = new char[8]{ 'r','r', 'r','g','g','g','g', 'g' };
			t[5] = new char[8]{ 'o','o','o','b','b' ,'b','b','b' };

			for (int i = 0; i < 6; i++) {
				Assert::AreEqual(c[i], g[i]);
				for (int j = 0; j < 8; j++)
					Assert::AreEqual(t[i][j], m[i][j]);
			}
		}
		TEST_METHOD(Move_Uprim)
		{
			Cube a;
			a.move("U'");
			vector<char> g = a.getCenter();
			vector<char> c = { 'w','y','o','r','g','b' };
			char** t = new char* [6];
			char** m = a.getSide();
			t[0] = new char[8]{ 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w' };
			t[1] = new char[8]{ 'y', 'y', 'y', 'y', 'y', 'y', 'y', 'y' };
			t[2] = new char[8]{ 'b','b', 'b', 'o', 'o', 'o', 'o', 'o' };
			t[3] = new char[8]{ 'g','g', 'g', 'r', 'r', 'r', 'r', 'r' };
			t[4] = new char[8]{ 'o','o','o','g','g','g','g', 'g' };
			t[5] = new char[8]{ 'r','r', 'r','b','b' ,'b','b','b' };

			for (int i = 0; i < 6; i++) {
				Assert::AreEqual(c[i], g[i]);
				for (int j = 0; j < 8; j++)
					Assert::AreEqual(t[i][j], m[i][j]);
			}
		}
		TEST_METHOD(Move_D)
		{
			Cube a;
			a.move("D");
			vector<char> g = a.getCenter();
			vector<char> c = { 'w','y','o','r','g','b' };
			char** t = new char* [6];
			char** m = a.getSide();
			t[0] = new char[8]{ 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w' };
			t[1] = new char[8]{ 'y', 'y', 'y', 'y', 'y', 'y', 'y', 'y' };
			t[2] = new char[8]{ 'o', 'o', 'o', 'o', 'o','b','b', 'b' };
			t[3] = new char[8]{  'r', 'r', 'r', 'r', 'r','g','g', 'g' };
			t[4] = new char[8]{ 'g','g','g','g', 'g', 'o','o','o' };
			t[5] = new char[8]{ 'b','b' ,'b','b','b','r','r', 'r' };

			for (int i = 0; i < 6; i++) {
				Assert::AreEqual(c[i], g[i]);
				for (int j = 0; j < 8; j++)
					Assert::AreEqual(t[i][j], m[i][j]);
			}
		}
		TEST_METHOD(Move_Dprim)
		{
			Cube a;
			a.move("D'");
			vector<char> g = a.getCenter();
			vector<char> c = { 'w','y','o','r','g','b' };
			char** t = new char* [6];
			char** m = a.getSide();
			t[0] = new char[8]{ 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w' };
			t[1] = new char[8]{ 'y', 'y', 'y', 'y', 'y', 'y', 'y', 'y' };
			t[2] = new char[8]{ 'o', 'o', 'o', 'o', 'o','g','g', 'g' };
			t[3] = new char[8]{ 'r', 'r', 'r', 'r', 'r','b','b', 'b' };
			t[4] = new char[8]{ 'g','g','g','g', 'g','r','r', 'r' };
			t[5] = new char[8]{ 'b','b' ,'b','b','b','o','o','o' };

			for (int i = 0; i < 6; i++) {
				Assert::AreEqual(c[i], g[i]);
				for (int j = 0; j < 8; j++)
					Assert::AreEqual(t[i][j], m[i][j]);
			}
		}
		TEST_METHOD(Move_F)
		{
			Cube a;
			a.move("F");
			vector<char> g = a.getCenter();
			vector<char> c = { 'w','y','o','r','g','b' };
			char** t = new char* [6];
			char** m = a.getSide();
			t[0] = new char[8]{ 'w', 'w', 'w', 'w', 'w', 'o', 'o', 'o' };
			t[1] = new char[8]{ 'y', 'y', 'y', 'y', 'y', 'r', 'r', 'r' };
			t[2] = new char[8]{ 'o', 'o', 'y', 'o', 'y', 'o', 'o', 'y' };
			t[3] = new char[8]{ 'r', 'r', 'w', 'r', 'w', 'r', 'r', 'w' };
			t[4] = new char[8]{ 'g','g','g','g', 'g','g','g', 'g' };
			t[5] = new char[8]{ 'b','b' ,'b','b','b','b','b','b' };

			for (int i = 0; i < 6; i++) {
				Assert::AreEqual(c[i], g[i]);
				for (int j = 0; j < 8; j++)
					Assert::AreEqual(t[i][j], m[i][j]);
			}
		}
		TEST_METHOD(Move_Fprim)
		{
			Cube a;
			a.move("F'");
			vector<char> g = a.getCenter();
			vector<char> c = { 'w','y','o','r','g','b' };
			char** t = new char* [6];
			char** m = a.getSide();
			t[0] = new char[8]{ 'w', 'w', 'w', 'w', 'w', 'r', 'r', 'r' };
			t[1] = new char[8]{ 'y', 'y', 'y', 'y', 'y', 'o', 'o', 'o' };
			t[2] = new char[8]{ 'o', 'o', 'w', 'o', 'w', 'o', 'o', 'w' };
			t[3] = new char[8]{ 'r', 'r', 'y', 'r', 'y', 'r', 'r', 'y' };
			t[4] = new char[8]{ 'g','g','g','g', 'g','g','g', 'g' };
			t[5] = new char[8]{ 'b','b' ,'b','b','b','b','b','b' };

			for (int i = 0; i < 6; i++) {
				Assert::AreEqual(c[i], g[i]);
				for (int j = 0; j < 8; j++)
					Assert::AreEqual(t[i][j], m[i][j]);
			}
		}
	};
	TEST_CLASS(CubeScrambles) 
	{
	public:
		TEST_METHOD(Scramble1) {
			Cube a;
			a.make_moves("U R2 U' L2 U' B2 D R2 D2 L2 U2 F' L2 F D' L2 R' D' L F2 L2");
			vector<char> g = a.getCenter();
			vector<char> c = { 'w','y','o','r','g','b' };
			char** t = new char* [6];
			char** m = a.getSide();
			t[0] = new char[8]{ 'g', 'y', 'y', 'b', 'b', 'y', 'g', 'b' };
			t[1] = new char[8]{ 'r', 'y', 'o', 'g', 'y', 'y', 'o', 'b' };
			t[2] = new char[8]{ 'o', 'y', 'g', 'g', 'r', 'w', 'r', 'g' };
			t[3] = new char[8]{ 'o', 'r', 'r', 'o', 'b', 'b', 'g', 'r' };
			t[4] = new char[8]{ 'o','o','w','w', 'w','r','b', 'y' };
			t[5] = new char[8]{ 'w','o' ,'b','w','w','g','r','w' };
			
			for (int i = 0; i < 6; i++) {
				Assert::AreEqual(c[i], g[i]);
				for (int j = 0; j < 8; j++)
					Assert::AreEqual(t[i][j], m[i][j]);
			}
		}
		TEST_METHOD(Scramble2) {
			Cube a;
			a.make_moves("D2 R F' U' L' D' F U R F' R2 D2 F L2 F L2 U2 L2 U2 B' D2");
			vector<char> g = a.getCenter();
			vector<char> c = { 'w','y','o','r','g','b' };
			char** t = new char* [6];
			char** m = a.getSide();
			t[0] = new char[8]{ 'w', 'b', 'w', 'r', 'o', 'w', 'b', 'y' };
			t[1] = new char[8]{ 'o', 'g', 'g', 'o', 'w', 'b', 'y', 'w' };
			t[2] = new char[8]{ 'b', 'y', 'g', 'b', 'r', 'b', 'g', 'y' };
			t[3] = new char[8]{ 'b', 'w', 'g', 'g', 'o', 'y', 'r', 'o' };
			t[4] = new char[8]{ 'r','w','r','g', 'y','r','b', 'g' };
			t[5] = new char[8]{ 'r','o' ,'o','r','w','y','y','o' };
			
			for (int i = 0; i < 6; i++) {
				Assert::AreEqual(c[i], g[i]);
				for (int j = 0; j < 8; j++)
					Assert::AreEqual(t[i][j], m[i][j]);
			}
		}
		TEST_METHOD(Scramble3) {
			Cube a;
			a.make_moves("B U D2 R U2 B U2 F L' B' R2 B' R2 U2 F2 U2 D2 F' U2 B'");
			vector<char> g = a.getCenter();
			vector<char> c = { 'w','y','o','r','g','b' };
			char** t = new char* [6];
			char** m = a.getSide();
			t[0] = new char[8]{ 'b', 'y', 'b', 'g', 'b', 'o', 'o', 'o' };
			t[1] = new char[8]{ 'y', 'w', 'g', 'b', 'r', 'g', 'g', 'y' };
			t[2] = new char[8]{ 'o', 'r', 'g', 'w', 'o', 'r', 'y', 'y' };
			t[3] = new char[8]{ 'w', 'o', 'b', 'r', 'b', 'w', 'w', 'b' };
			t[4] = new char[8]{ 'w','y','w','g', 'r','o','w', 'r' };
			t[5] = new char[8]{ 'y','g' ,'r','b','y','g','o','r' };

			for (int i = 0; i < 6; i++) {
				Assert::AreEqual(c[i], g[i]);
				for (int j = 0; j < 8; j++)
					Assert::AreEqual(t[i][j], m[i][j]);
			}
		}
	};
	TEST_CLASS(Algorithm) {
	public:
		TEST_METHOD(AlgorytmReverse1) {
			Cube a;
			string alg = "R' U F S";
			string expectedAlgRev = "S' F' U' R ";
			Assert::AreEqual(expectedAlgRev, a.algReverse(alg));
		}
		TEST_METHOD(AlgorytmReverse2) {
			Cube a;
			string alg = "R2 d R' E2";
			string expectedAlgRev = "E2 R d' R2 ";
			Assert::AreEqual(expectedAlgRev, a.algReverse(alg));
		}
	};
}
