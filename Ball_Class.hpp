#ifndef BALLAR
#define BALLAR
#include "Position.hpp"

class ball 
{
	public:	
		ball (int x1, int y, int v,int i);
		int get_x_speed ();
		int get_y_speed ();
		int get_value ();
		int get_postion ();
		int get_id ();
		
	private:
		int x_speed,y_speed,value,id;
		Position x;
};
#endif
