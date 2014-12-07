CC=g++
CFLAGS=-std=c++11 -pthread -I include/ -c
SOURCES=Armor.cpp Bracket.cpp Character.cpp Characters.cpp GameUtil.cpp HealthPotion.cpp Inventory.cpp Item.cpp main.cpp ManaPotion.cpp Party.cpp Potion.cpp Shop.cpp Tournament.cpp Weapon.cpp
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
