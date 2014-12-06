CC=g++
CFLAGS=-std=c++11 -pthread -I include/ -c
SOURCES=Armor.cpp Character.cpp Characters.cpp Equipment.cpp GameUtil.cpp HealthPotion.cpp Item.cpp ManaPotion.cpp Potion.cpp Weapon.cpp
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
