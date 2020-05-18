all: point.o main.o triangle.o 
	g++ point.o main.o triangle.o -o prog

point.o: 
	g++ -c point.cpp 

triangle.o:
	g++ -c triangle.cpp

main.o: 
	g++ -c main.cpp

run:
	./prog

clean:  
	rm *.o prog