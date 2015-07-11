#include "Ball_Class.hpp"

	int Ball::get_x_speed ()
	{
		return x_speed;
	}
	int Ball::get_y_speed ()
	{
		return y_speed;
	}
	int Ball::get_value ()
	{
		return value;
	}
	int Ball::get_postion ()
	{
		return true; //should be x;
	}
	int Ball::get_id ()
	{
		return id; 
	}
	Ball::Ball (int x1, int y, int v,int i)
	{
		x = position(x1,y);
		value = v; 
		id =i; 
	}
