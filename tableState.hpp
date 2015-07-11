#ifndef TABLESTATECLASS
#define TABLESTATECLASS

#include "Hole.hpp"
#include "Ball_Class.hpp"
#include "GameConstant.hpp"

class TableState {
	public: 
		GameConstant gc; 
		TableState();
		TableState update (int t);
		int c_time;
		bool collisionWall (Ball b);
		bool collisionBall (int v);
		Ball whoHit (int v);
	private:
		Hole* holes;
		Ball* balls;
};

#endif
