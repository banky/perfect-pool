#include <iostream>
#include "shot.h"
#include "tableState.hpp"
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
//Check if there is a ball between our current ball and a hole

bool isBallInLine (Hole hole, TableState tableState) {
	int length = sizeof((tableState.getBall))/sizeof((tableState.getBall)[0]);
	int distanceToHole = sqrt(pow((position.x - hole.position.x),2) + pow((position.y - hole.position.y),2));
	int distanceInX = hole.position.x - position.x;
	int distanceInY = hole.position.y - position.y;
	for(int i = 0; i < length; i++) {
		int tempBallX = position.x;
		int tempBallY = position.y;
		while(pow((tempBallX - hole.position.x),2) + pow((tempBallY - hole.position.y),2) <= pow((radius - holeRadius),2)) {
			if(pow((tempBallX - tableState.balls[i]) {
				
			}
			//Use a base value as 1mm
			tempBallX += distanceInX/distanceToHole;
			tempBallY += distanceInY/distanceToHole;
		}
				
	}
}

double velocityFromDistance(int distance) {
	//assume ball needs to sink within 5 seconds
	//math and shit
	//note log is actually ln
	GameConstant gc;
	return (distance * gc.Alpha() / (log(5) - 1) );
}

//shots should have length 6
//returns 0 if not possible
void velocityToGetBallIn (Ball ball, Hole hole, int* velXOut, int* velYOut) {
	GameConstant gc = GameConstant.getInstance();
	if(!isBallInLine(hole, tableState) {
		int dx = this.position.x - hole.position.x;
		int dy = this.position.y - hole.position.y;
		
		double vx = velocityFromDistance(dx);
		double vy = velocityFromDistance(dy);
		
		velXOut = (int) vx + 5;
		velYOut = (int) vy + 5;
		
	} else {
		velXOut = 0;
		velYOut = 0;
	}
}



