Bank: driver.o Event.o
	g++ -o Bank driver.o Event.o

driver.o: driver.cpp PriorityArrayQueue.h Event.h
	g++ -c driver.cpp

Event.o: Event.cpp 
	g++ -c Event.cpp

clean:
	rm  *.o Bank