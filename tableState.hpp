#ifndef TABLESTATECLASS
#define TABLESTATECLASS

#include "position.hpp"

class TableState {
	public: 
		TableState();
		TableState update (int t);
	private:
		Position* holesT;
		Position* ballsT;
};

#endif
