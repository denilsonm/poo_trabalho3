CC=g++
CFLAGS=-std=c++11 -pthread -I include/ -c
SOURCES=Item.cpp Potion.cpp
OBJECTS=$(addprefix obj/, $(SOURCES:.cpp=.o))
EXECUTABLE=Trabalho2

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(OBJECTS) -o $@

obj/%.o: src/%.cpp
	$(CC) $(CFLAGS) $< -o $@

run: $(EXECUTABLE)
	./$(EXECUTABLE)

clean:
	rm -f obj/*.o ./$(EXECUTABLE)
