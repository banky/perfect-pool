#include "tableState.hpp"
#include "Ball_Class.hpp"
#include "Hole.hpp"
#include <cmath>

int tableLength;
int tableWidth;


bool TableState::collisionWall (Ball b)
{
	
	for(int i=0;i<15;i++)
	{
		if (b.position.y >= gc.Length())
			return true;
		if (b.position.x >= gc.Width())
			return true; 
	}
	return false; 
}
bool TableState::collisionBall (int v)
{
	int r = balls[v].getRadius();
	for(int i=0; i <v; i++)
	{
		if (abs(balls[i].position.x - balls[v].position.x) <= 2*r)
			if (abs(balls[i].position.y - balls[v].position.y) <= 2*r)
				return true;
	}
	for(int i =15; i>v;i--)
	{
		if (abs(balls[i].position.x - balls[v].position.x) <= 2*r)
			if (abs(balls[i].position.y - balls[v].position.y) <= 2*r)
				return true;
	}
}
Ball TableState::whoHit (int v)
{
	int r = balls[v].getRadius();
	for(int i=0; i <v; i++)
	{
		if (abs(balls[i].position.x - balls[v].position.x) <= 2*r+2)
			if (abs(balls[i].position.y - balls[v].position.y) <= 2*r+2)
				return balls[i];
		
	}
	for(int i =15; i>v;i--)
	{
		if (abs(balls[i].position.x - balls[v].position.x) <= 2*r+2)
			if (abs(balls[i].position.y - balls[v].position.y) <= 2*r+2)
				return balls[i];
	}
}

ballIsOnAnother (int x, int y, GameConstant gameConstant) {
	for(int i = 0; i < 15; i++) {
		if(sqrt(pow((x - ball[i].position.x),2) + pow((y - ball[i].position.y),2))) {
			return true;
		}
	}
	return false;
}

TableState TableState::update (int ms)
{	
	TableState temp = (*this);
	
	for(int cms=0; cms<ms; cms++)
	{
		for(int i=0;i<15;i++)
		{
			balls[i].position.x += balls[i].x_speed;
			balls[i].position.y += balls[i].y_speed;
			if (collisionWall(balls[i]))
			{
				balls[i].tableCollision();	
			}
			else if (collisionBall(i))
			{
				balls[i].ballCollision(whoHit(i));
			}
			balls[i].x_speed-= (gc.Alpha()*pow(balls[i].x_speed,2));
			balls[i].y_speed-= (gc.Alpha()*pow(balls[i].y_speed,2));
			
			if (balls[i].x_speed <= gc.VelocityThreshold())
				balls[i].x_speed = 0;
			if (balls[i].y_speed <= gc.VelocityThreshold())
				balls[i].y_speed = 0;
			
			for(int j = 0; j < 6; j++) {
				if(sqrt(pow((balls[i].position.x - holes[j].position.x),2) + pow((balls[i].position.y - holes[j].position.y),2))){
					//Set the white ball position to a random location
					if(balls[i].get_id() == 1) {
						balls[i].position.y = rand() % tableLength + (tableLength/2);
						balls[i].position.x = rand() %tableWidth;
					
						//If the ball is on another ball, try to place it elsewhere
						while(ballIsOnAnother(balls[i].position.x, balls[i].position.y)) {	
							balls[i].position.y = rand() % tableLength + (tableLength/2);
							balls[i].position.x = rand() %tableWidth;
						}
					}

					balls[i].x_speed = 0;
					balls[i].y_speed = 0;
					balls[i].position.x = -10;
					balls[i].position.y = -10;
				}
			}
		}
	}
}



TableState::TableState() {
	holes = new Hole[6];
	balls = new Ball[16];
}
