CXX = g++
SDL = -LC:\SDL2\lib -LC:\SDL2_ttf\lib -lmingw32 -lSDL2main -lSDL2 -lSDL2_ttf
CXXFLAGS = -Wall -std=c++11 -IC:\SDL2_ttf\include\SDL2 -IC:\SDL2\include\SDL2

LDFLAGS = $(SDL)
EXE = ml
BIN_FOLDER = bin
SRC_FOLDER = src
OBJ_FOLDER = obj

CPP_FILES := $(wildcard src/*.cpp)

all:
	$(CXX) $(CPP_FILES) $(CXXFLAGS) $(LDFLAGS) -o $(EXE)

clean:
	del /q obj\*
	del $(BIN_FOLDER)\*.exe

rebuild:
	make clean
	make

