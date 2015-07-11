#ifndef TABLESTATECLASS
#define TABLESTATECLASS

#include "Hole.hpp"
#include "Ball_Class.hpp"

class TableState {
	public: 
		TableState();
		TableState update (int t);
	private:
		Hole* holes;
		Ball* balls;
};

#endif
