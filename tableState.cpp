#include "tableState.hpp"
#include "Ball_Class.hpp"

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
	holesT = new holes [6];
	ballsT = new ball  [11];
	holes = new Position[6];
	balls = new Position[11];
}
