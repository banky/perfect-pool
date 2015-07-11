#ifndef BALLAR
#define BALLAR
#include "Position.hpp"

class Ball 
{
	public:	
		Ball (int x1, int y, int v,int i);
		int get_x_speed ();
		int get_y_speed ();
		int get_value ();
		int get_postion ();
		int get_id ();
		int getRadius();
		void ball_collision(ball b);		
	private:
		int x_speed,y_speed,value,id,radius;
		Postion position;
};
#endif
