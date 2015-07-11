#include "Ball_Class.hpp"
#include "position.hpp"
#include <cmath>

//TODO: I'm not too sure how to get the mass value
int mass;

//Our time constant
double dt = 0.001;
int tableLength;
int tableWidth;

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
