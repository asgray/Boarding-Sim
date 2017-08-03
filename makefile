SimulationProject.exe: SimulationProject.o PrecondViolatedExcep.o Airworthy.o Passenger.o
	g++ -std=gnu++11 -o SimulationProject.exe SimulationProject.o PrecondViolatedExcep.o Airworthy.o Passenger.o
SimulationProject.o: SimulationProject.cpp PrecondViolatedExcep.h 
	g++ -std=gnu++11 -ggdb -c SimulationProject.cpp
PrecondViolatedExcep.o: PrecondViolatedExcep.h PrecondViolatedExcep.cpp
	g++ -std=gnu++11 -ggdb -c PrecondViolatedExcep.cpp
Airworthy.o: Airworthy.h Airworthy.cpp Heap_PriorityQueue.h Passenger.h
	g++ -std=gnu++11 -ggdb -c Airworthy.cpp
Passenger.o: Passenger.h Passenger.cpp
	g++ -std=gnu++11 -ggdb -c Passenger.cpp