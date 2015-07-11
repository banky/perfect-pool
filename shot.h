#ifndef SHOTCLASS
#define SHOTCLASS

class Shot {
	public:
		Shot(int, int, Position);
		
		const Position NULL_POSITION = Position(-1, -1);
		int xVel;
		int yVel;
		Position resetPosition;
};

#endif
