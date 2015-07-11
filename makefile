CC = g++

test: main.o Ball_Class.o position.o shot.o tableState.o
	$(CC) -o test main.o Ball_Class.o position.o shot.o tableState.o
	
main.o Ball_Class.o position.o shot.o tableState.o: main.cpp Ball_Class.cpp position.cpp shot.cpp tableState.cpp
	$(CC) -c main.cpp Ball_Class.cpp position.cpp shot.cpp tableState.cpp
	
clean:
	rm -f *.o