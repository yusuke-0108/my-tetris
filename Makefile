CXX = g++-11
SRC_PATH = /work/src/
OBJ_PATH = /work/src/.obj/
TARGET = run
SFML_LIBS = -lsfml-graphics -lsfml-window -lsfml-system

PCH = $(OBJ_PATH)common_header.hpp.gch
OBJS = $(OBJ_PATH)display.o \
	   $(OBJ_PATH)field.o \
	   $(OBJ_PATH)create_mino.o \
	   $(OBJ_PATH)rotate_mino.o \
	   $(OBJ_PATH)tetrimino.o \
	   $(OBJ_PATH)hit.o \
	   $(OBJ_PATH)main.o

CXXFLAGS = -I $(SRC_PATH)/common

all: common compile link

common: $(SRC_PATH)common/header.hpp
	$(CXX) -x c++-header $< -o $(OBJ_PATH)common_header.hpp.gch

compile: $(OBJS)

$(OBJ_PATH)display.o: $(SRC_PATH)display/display.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@ $(SFML_LIBS)

$(OBJ_PATH)field.o: $(SRC_PATH)field/field.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@ $(SFML_LIBS)

$(OBJ_PATH)create_mino.o: $(SRC_PATH)tetrimino/create_mino.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@ $(SFML_LIBS)

$(OBJ_PATH)rotate_mino.o: $(SRC_PATH)tetrimino/rotate_mino.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@ $(SFML_LIBS)

$(OBJ_PATH)tetrimino.o: $(SRC_PATH)tetrimino/tetrimino.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@ $(SFML_LIBS)

$(OBJ_PATH)hit.o: $(SRC_PATH)hit/hit.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@ $(SFML_LIBS)

$(OBJ_PATH)main.o: $(SRC_PATH)main.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@ $(SFML_LIBS)

link:
	$(CXX) -o $(TARGET) $(OBJS) $(SFML_LIBS)

# all: Tetris

# ObjectFile/GetMINO.o: GetMINO.cpp Tetris.hpp
# 	$(CXX) -c GetMINO.cpp -o ObjectFile/GetMINO.o

# ObjectFile/MoveMINO.o: MoveMINO.cpp Tetris.hpp
# 	$(CXX) -c MoveMINO.cpp -o ObjectFile/MoveMINO.o

# ObjectFile/RotateMINO.o: RotateMINO.cpp Tetris.hpp
# 	$(CXX) -c RotateMINO.cpp -o ObjectFile/RotateMINO.o

# ObjectFile/DetectHit.o: DetectHit.cpp Tetris.hpp
# 	$(CXX) -c DetectHit.cpp -o ObjectFile/DetectHit.o

# ObjectFile/DrawGrid.o: DrawGrid.cpp Tetris.hpp
# 	$(CXX) -c DrawGrid.cpp -o ObjectFile/DrawGrid.o

# ObjectFile/main.o: main.cpp Tetris.hpp
# 	$(CXX) -c main.cpp -o ObjectFile/main.o

# Tetris: ObjectFile/DrawGrid.o ObjectFile/GetMINO.o ObjectFile/MoveMINO.o ObjectFile/main.o ObjectFile/RotateMINO.o ObjectFile/DetectHit.o
# 	$(CXX) ObjectFile/DrawGrid.o ObjectFile/GetMINO.o ObjectFile/MoveMINO.o ObjectFile/RotateMINO.o ObjectFile/DetectHit.o ObjectFile/main.o -o Tetris $(SFML_LIBS)