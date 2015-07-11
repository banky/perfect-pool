#ifndef BALLAR
#define BALLAR
#include "Position.hpp"

class Ball 
{
	public:	
		Ball (int x1, int y, int v,int i);
		Ball ();
		int x_speed,y_speed;
		Position position;
		int get_value ();
		int get_postion ();
		int get_id ();
		int getRadius();
		void ballCollision(Ball b);		
		void tableCollision();
	private:
		int value,id,radius;
		
};
#endif
