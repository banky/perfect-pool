#include "tableState.hpp"
#include "Ball_Class.hpp"
#include "Hole.hpp"

bool collisionWall (Ball b)
{
	
}
bool collisionBall (Ball b)
{
	
}
Ball whoHit ()
{
	
}
TableState TableState::update (int ms)
{	int ctime = TableState::c_time;
	TableState temp;
	if (ms > ctime)
	for(int cms=ctime; cms<ms; cms++)
	{
		for(int i=0;i<10;i++)
		{
			balls[i].position.x += balls[i].x_speed;
			balls[i].position.y += balls[i].y_speed;
			if (collisionWall(balls[i]))
			{
				balls[i].ballCollision(whoHit());
			}
			else if (collisionBall(balls[i]))
			{
				balls[i].tableCollision();
			}
		}
	}
}

TableState::TableState() {
	holes = new Hole[6];
	balls = new Ball[11];
}
