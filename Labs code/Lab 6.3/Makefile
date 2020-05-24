#$^ list of all the dependencies (including the first one, denoted by $<)
all: main.o game.o ninja.o samurai.o warrior.o
	g++ $^ -o prog

#implicit rule	
#$< variable denotes the first dependency, %.cpp here.
%.o : %.cpp %.hpp
	g++ -c $<

run:
	./prog
	
clean:
	rm *.o prog