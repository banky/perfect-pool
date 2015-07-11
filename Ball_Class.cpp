#include "Ball_Class.hpp"

	int ball::get_x_speed ()
	{
		return x_speed;
	}
	int ball::get_y_speed ()
	{
		return y_speed;
	}
	int ball::get_value ()
	{
		return value;
	}
	int ball::get_postion ()
	{
		return true; //should be x;
	}
	int ball::get_id ()
	{
		return id; 
	}
	ball::ball (int x1, int y, int v,int i)
	{
		x = position(x1,y);
		value = v; 
		id =i; 
	}
