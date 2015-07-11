#ifndef SHOTCLASS
#define SHOTCLASS
#include "position.hpp"
class Shot {
	public:
		Shot(int, int, Position);
		static Shot random();
		int xVel;
		int yVel;
		Position resetPosition;
};

#endif
