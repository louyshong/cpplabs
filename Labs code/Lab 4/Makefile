#$^ list of all the dependencies (including the first one, denoted by $<)
all: polynomial.o labeled_point.o main.o point.o
	g++ $^ -o prog

#implicit rule	
#$< variable denotes the first dependency, %.cpp here.
%.o : %.cpp %.hpp
	g++ -c $<

run:
	./prog
	
clean:
	rm *.o prog