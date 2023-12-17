CXX = /usr/bin/g++-11
SFML_LIBS = -lsfml-graphics -lsfml-window -lsfml-system

all: Tetris

ObjectFile/GetMINO.o: GetMINO.cpp Tetris.hpp
	$(CXX) -c GetMINO.cpp -o ObjectFile/GetMINO.o

ObjectFile/MoveMINO.o: MoveMINO.cpp Tetris.hpp
	$(CXX) -c MoveMINO.cpp -o ObjectFile/MoveMINO.o

ObjectFile/RotateMINO.o: RotateMINO.cpp Tetris.hpp
	$(CXX) -c RotateMINO.cpp -o ObjectFile/RotateMINO.o

ObjectFile/DetectHit.o: DetectHit.cpp Tetris.hpp
	$(CXX) -c DetectHit.cpp -o ObjectFile/DetectHit.o

ObjectFile/DrawGrid.o: DrawGrid.cpp Tetris.hpp
	$(CXX) -c DrawGrid.cpp -o ObjectFile/DrawGrid.o

ObjectFile/main.o: main.cpp Tetris.hpp
	$(CXX) -c main.cpp -o ObjectFile/main.o

Tetris: ObjectFile/DrawGrid.o ObjectFile/GetMINO.o ObjectFile/MoveMINO.o ObjectFile/main.o ObjectFile/RotateMINO.o ObjectFile/DetectHit.o
	$(CXX) ObjectFile/DrawGrid.o ObjectFile/GetMINO.o ObjectFile/MoveMINO.o ObjectFile/RotateMINO.o ObjectFile/DetectHit.o ObjectFile/main.o -o Tetris $(SFML_LIBS)