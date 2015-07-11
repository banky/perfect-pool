#ifndef TABLESTATECLASS
#define TABLESTATECLASS

#include "Hole.hpp"
#include "Ball_Class.hpp"

class TableState {
	public: 
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
