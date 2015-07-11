#include "shot.h"

Shot::Shot(int x, int y, Position p) {
	xVel = x;
	yVel = y;
	resetPosition = p;
}

Shot::random(GameConstant gc) {
	xVel = rand() % gc.MaxXVelocity();
	yVel = rand() % gc.MaxYVelocity();
}