UNAME := $(shell uname)

ifeq ($(UNAME), Darwin)
	CXX = clang++
	SDL = -I/Library/Frameworks/SDL2.framework/Headers -I/Library/Frameworks/SDL2_ttf.framework/Headers -F/Library/Frameworks -framework SDL2 -framework SDL2_ttf
	CXXFLAGS = -Wall -c -std=c++11 -F/Library/Frameworks
endif
ifeq ($(UNAME), Linux)
	CXX = g++
	SDL = -lSDL2 -lSDL2_ttf
	CXXFLAGS = -Wall -c -std=c++11
endif
LDFLAGS = $(SDL)
EXE = ml
BIN_FOLDER = bin
SRC_FOLDER = src
OBJ_FOLDER = obj

CPP_FILES := $(wildcard src/*.cpp)
OBJ_FILES := $(addprefix $(OBJ_FOLDER)/,$(notdir $(CPP_FILES:.cpp=.o)))

all: $(EXE)

$(EXE): $(OBJ_FILES)
	mkdir -p $(BIN_FOLDER)
	$(CXX) $(LDFLAGS) $^ -o $(BIN_FOLDER)/$@

obj/%.o: src/%.cpp
	mkdir -p $(OBJ_FOLDER)
	$(CXX) $(CXXFLAGS) $< -o $@

clean:
	rm obj/*.o && rm $(BIN_FOLDER)/$(EXE)

rebuild:
	make clean
	make
