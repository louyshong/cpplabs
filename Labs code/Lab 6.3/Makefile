# --------- Variables ---------
TARGET = bin/main
OBJECTS = bin/warrior.o bin/ninja.o bin/samurai.o bin/game.o $(TARGET).o

# --------- Compiler ----------
CC = g++
CCFLAGS = -Wall

# --------- Compiling Options ----------
INCFLAGS = -I ./inc 
#LIBFLAGS = -L ./lib

# --------- Compiling ----------
bin/%.o : src/%.cpp
	$(CC) $(CCFLAGS) $(INCFLAGS) -c $< -o $@

# --------- Linking ----------
all : $(TARGET)

$(TARGET) : $(OBJECTS)
	$(CC) $(OBJECTS) -o $(TARGET)

# --------- Running ----------
run : 
	./$(TARGET)

# --------- Cleaning ----------
clean : 
	rm bin/*.o $(TARGET)