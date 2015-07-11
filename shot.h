#ifndef SHOTCLASS
#define SHOTCLASS

class Shot {
	public:
		Shot(int, int, Position);
		
		int xVel;
		int yVel;
		Position resetPosition;
};

#endif
