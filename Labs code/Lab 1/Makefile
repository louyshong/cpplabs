all: point.o main.o triangle.o 
	g++ point.o main.o triangle.o -o prog

point.o: point.cpp point.hpp
	g++ -c point.cpp 

triangle.o: triangle.cpp triangle.hpp point.hpp
	g++ -c triangle.cpp

main.o: main.cpp point.hpp triangle.hpp
	g++ -c main.cpp

run:
	./prog

clean:  
	rm *.o prog