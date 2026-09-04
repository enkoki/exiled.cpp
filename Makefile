CXX = g++

CXXFLAGS = -I include \
           -I include/entities \
           -I include/battle \
           -I include/entities/player \
           -I include/entities/player/classes \
           -I include/entities/npc

SRCS = main.cpp \
       src/ascii/UI.cpp \
       src/battle/Battle.cpp \
       src/entities/Character.cpp \
       src/entities/player/Player.cpp \
       src/entities/player/classes/Warrior.cpp \
       src/entities/player/classes/Samurai.cpp \
       src/entities/npc/Enemy.cpp

TARGET = game

run: $(TARGET)
	./$(TARGET)

$(TARGET): $(SRCS)
	$(CXX) $(CXXFLAGS) $(SRCS) -o $(TARGET)

clean:
	rm -f $(TARGET)