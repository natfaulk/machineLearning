CXX = clang++
SDL = -I/Library/Frameworks/SDL2.framework/Headers -I/Library/Frameworks/SDL2_ttf.framework/Headers -F/Library/Frameworks -framework SDL2 -framework SDL2_ttf 
# If your compiler is a bit older you may need to change -std=c++11 to -std=c++0x
CXXFLAGS = -Wall -c -std=c++11 -F/Library/Frameworks
LDFLAGS = $(SDL)
EXE = ml
BIN_FOLDER = bin
SRC_FOLDER = src

CPP_FILES := $(wildcard src/*.cpp)
OBJ_FILES := $(addprefix obj/,$(notdir $(CPP_FILES:.cpp=.o)))

all: $(EXE)

$(EXE): $(OBJ_FILES)
	$(CXX) $(LDFLAGS) $^ -o $(BIN_FOLDER)/$@

obj/%.o: src/%.cpp
	$(CXX) $(CXXFLAGS) $< -o $@

clean:
	rm obj/*.o && rm $(BIN_FOLDER)/$(EXE)

rebuild:
	make clean
	make
