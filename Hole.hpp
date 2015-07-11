#ifndef HOLE
#define HOLE

#include "Position.hpp"

struct Hole
{
	Hole (Position in, int r1)
	{
		i = in; 
		r = r1; 
	}
	Hole ()
	{
		r=-1;
	}
	Position i;
	int r;
};

#endif
