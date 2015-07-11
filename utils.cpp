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
/*
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

void Ball::velocityToGetBallIn (TableState tableState) {
    int length = sizeof(tableState.holes)/sizeof(tablState.holes[0]);
	for (int i = 0; i < length; i++) {
		
	
	}
*/


