#ifndef TABLESTATECLASS
#define TABLESTATECLASS

#include "Hole.hpp"
#include "Ball_Class.hpp"
#include "GameConstant.hpp"

class TableState {
	public: 
		GameConstant gc; 
		TableState();
		TableState& operator=(TableState& other)
		{
			for (int i=0; i<15;i++)
			{
				(other.getHole())[i] = holes[i];
				(other.getBall())[i] = balls[i];
			}
		}
		TableState update (int t);
		bool collisionWall (Ball b);
		bool collisionBall (int v);
		Ball whoHit (int v);
		Hole* getHole ()
		{
			return holes; 
		}
		Ball* getBall ()
		{
			return balls;
		}
	private:
		Hole* holes;
		Ball* balls;
};

#endif
