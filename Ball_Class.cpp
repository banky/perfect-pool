#include "Ball_Class.hpp"
#include "Hole.hpp"
#include "position.hpp"
#include "Ball_Class"
#include <cmath>

//TODO: I'm not too sure how to get the mass value
int mass;

//Our time constant
double dt = 0.001;
int tableLength;
int tableWidth;
int holeRadius;

Ball::Ball()
{
	
}
int Ball::get_value () {
	return value;
}
int Ball::get_postion () {
	return true; //should be x;
}
int Ball::get_id () {
	return id;
}
Ball::Ball (int x1, int y, int v,int i) {
    position = Position(x1,y);
	value = v;
	id =i;
}
int Ball::getRadius() {
	return radius;
}

void Ball::ballCollision(Ball b) {
	int d = sqrt(pow((position.x - b.position.x),2) + pow((position.y - b.position.y), 2));
	int nx = (b.position.x - position.x)/d;
	int ny = (b.position.y - position.y)/d;
    int p = (2 * (x_speed * nx + y_speed * ny - b.x_speed * nx - b.y_speed * ny))/(mass + mass);
    x_speed = x_speed - p * mass * nx;
    y_speed = y_speed - p * mass * ny;
    b.x_speed = b.x_speed + p * mass * nx;
    b.y_speed = b.y_speed + p * mass * ny;
    
    position.x += x_speed * dt;
    position.y += y_speed * dt;
    b.position.x += b.x_speed * dt;
    b.position.y += b.y_speed * dt;
}

void Ball::tableCollision() {
    if (((position.x - radius) < 0) || ((position.x + radius) > tableWidth)) {
		x_speed *= -1;
		position.x += x_speed * dt;
	}
	if (((position.y - radius < 0) || ((position.y + radius) > tableLength))) {
		y_speed *= -1;
		position.y += y_speed * dt;
	}
}


double velocityFromDistance(int distance) {
	//assume ball needs to sink within 5 seconds
	//math and shit
	//note log is actually ln
	return (distance + (0.5 * log(5))) / 5.0;
}

//shots should have length 6
void Ball::velocityToGetBallIn (TableState tableState, Shot* shots) {
	GameConstant gc = GameConstant.getInstance();
	for (int i = 0; i < 6; i++) {
		Hole hole = tablestate.holes[i];
		if(!isBallInLine(hole, tableState) {
			int dx = this.position.x - hole.position.x;
			int dy = this.position.y - hole.position.y;
			
			double vx = velocityFromDistance(dx);
			double vy = velocityFromDistance(dy);
			
			shots[i] = Shot(vx, vy, Position());
		}
	}
}

//Check if there is a ball between our current ball and a hole
bool Ball::isLineFree (Hole hole, TableState tableState) {
	int length = sizeof(tableState.balls)/sizeof(tableState.balls[0]);
	int distanceToHole = sqrt(pow((position.x - hole.position.x),2) + pow((position.y - hole.position.y),2));
	int distanceInX = hole.position.x - position.x;
	int distanceInY = hole.position.y - position.y;
	for(int i = 0; i < length; i++) {
		int tempBallX = position.x;
		int tempBallY = position.y;
		while(sqrt(pow((position.x - hole.position.x),2) + pow((position.y - hole.position.y),2)) <= holeRadius) {
			if(pow((tempBallX - tableState.balls[i].position.x),2) < radius*2) {
				return false;
			}
			//Use a base value as 1mm
			tempBallX += distanceInX/distanceToHole;
			tempBallY += distanceInY/distanceToHole;
		}	
	}
	return true;
}

