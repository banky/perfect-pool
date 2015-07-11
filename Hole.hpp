
#ifndef HOLE
#define HOLE

#include "Position.hpp"

struct Hole
{
	Hole (Position in, int r1);
	Position i;
	int r;
};

Hole::Hole (Position in, int r1)
{
	i = in; 
	r = r1; 
}
#endif
