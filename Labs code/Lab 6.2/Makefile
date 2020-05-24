#$^ list of all the dependencies (including the first one, denoted by $<)
all: main.o triangle.o point.o shape.o square.o
	g++ $^ -o prog

#implicit rule	
#$< variable denotes the first dependency, %.cpp here.
%.o : %.cpp %.hpp
	g++ -c $<

run:
	./prog
	
clean:
	rm *.o progs