#include "tableState.hpp"
#include "Ball_Class.hpp"
#include "Hole.hpp"

TableState TableState::update (int ms)
{
	TableState temp;
	for(int cms=0; cms<ms; cms++)
	{
		for(int i=0;i<10;i++)
		{
			
		}
	}
}

TableState::TableState() {
	holes = new Hole[6];
	balls = new Ball[11];
}
