#include <iostream>
#include "GameConstant.hpp"
#include "utils.cpp"
#include <fstream>
#include <vector>
#include "Ball_Class.hpp"
using namespace std;

void initializeHoles(Hole* holes, GameConstant gc) {
	holes[0].i.x = 0 + gc.PocketOffset();
	holes[0].i.y = 0 + gc.PocketOffset();
	holes[0].r = gc.PocketRadius();
	
	holes[1].i.x = 0 + gc.PocketOffset();
	holes[1].i.y = gc.Length() / 2;
	holes[1].r = gc.PocketRadius();
	
	holes[2].i.x = 0 + gc.PocketOffset();
	holes[2].i.y = gc.Length() - gc.PocketOffset();
	holes[2].r = gc.PocketRadius();
	
	holes[3].i.x = gc.Width() - gc.PocketOffset();
	holes[3].i.y = 0 + gc.PocketOffset();
	holes[3].r = gc.PocketRadius();
	
	holes[4].i.x = gc.Width() - gc.PocketOffset();
	holes[4].i.y = gc.Length() / 2;
	holes[4].r = gc.PocketRadius();
	
	holes[5].i.x = gc.Width() - gc.PocketOffset();
	holes[5].i.y = gc.Length() - gc.PocketOffset();
	holes[5].r = gc.PocketRadius();
}

void outputRandomShots (ostream& out) {
	Shot* shots = new Shot[10];
	for(int i = 0; i < 10; i++) {
		shots[i] = Shot.random();
	}
	output(out, shots, 10);
}

int main () {
	ifstream fin("sample_table.data");
	GameConstant gc;
	vector<Ball> ballVector;
	extractFileInput(fin, &gc, &ballVector);
	
	TableState tableState;
	tableState.holes = new Hole[6];
	initializeHoles(tableState.holes, gc);
	Ball* ballArray = &ballVector[0];
	tableState.balls = ballArray;
	
	ofstream fout("output.txt");
	outputRandomShots(fout);
	fout.close();
	return 0;
}