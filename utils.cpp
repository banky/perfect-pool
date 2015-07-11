#include <iostream>
#include "shot.h"
#include "Ball_Class.hpp"
#include "position.hpp"
#include "GameConstant.hpp"
#include <sstream>
#include <vector>

using namespace std;

void output (ostream &out, Shot* shots, int length)
{
	for(int i = 0; i < length; i++) {
		Shot s = shots[i];
		out << "[" 
		<< s.xVel << ", " 
		<< s.yVel << ", " 
		<< s.resetPosition.x 
		<< ", " << s.resetPosition.y << "]\n";
	}
}

int getNextInt(istream& in) {
	char c = 'l';
	while(c!='='){
		in >> c;
	}
	int n;
	in >> n;
	return n;
}
double getNextDouble(istream& in) {
	char c = 'l';
	while(c!='='){
		in >> c;
	}
	double d;
	in >> d;
	return d;
}

Ball getBallFromInput(istream& in, int ballNum) {
	char c = 'l';
	while(c!='[') {
		in >> c;
	}
	int x, y, z;
	in >> x >> c >> y >> c >> z;
	Ball b(x, y, z, ballNum);
	
}

void extractFileInput(istream& in, GameConstant* gc, vector<Ball>* balls) {
	double alpha = getNextDouble(in);
	double dt = getNextDouble(in);
	double vel_thresh = getNextDouble(in);
	
	int numShots = getNextInt(in);
	int maxXVel = getNextInt(in);
	int maxYVel = getNextInt(in);
	
	int width = getNextInt(in);
	int length = getNextInt(in);
	int b_radius = getNextInt(in);
	int pocket_radius = getNextInt(in);
	int pocket_offset = getNextInt(in);
	
	*gc = GameConstant(alpha, dt, vel_thresh, numShots, maxXVel, maxYVel,
	width, length, b_radius, pocket_radius, pocket_offset);
	
	for(int i = 1; i < 16; i++)
		balls->push_back(getBallFromInput(in, i));
}
