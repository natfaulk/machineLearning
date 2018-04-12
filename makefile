ifeq ($(OS),Windows_NT)
	CXX = g++
	SDL = -LC:\SDL2\lib -LC:\SDL2_ttf\lib -lmingw32 -lSDL2main -lSDL2 -lSDL2_ttf
	CXXFLAGS = -Wall -std=c++11 -IC:\SDL2_ttf\include -IC:\SDL2\include -IC:\SDL2\include\SDL2
else
	UNAME := $(shell uname)
endif
ifeq ($(UNAME), Darwin)
	CXX = clang++
	SDL = -I/Library/Frameworks/SDL2.framework/Headers -I/Library/Frameworks/SDL2_ttf.framework/Headers -F/Library/Frameworks -framework SDL2 -framework SDL2_ttf
	CXXFLAGS = -Wall -std=c++11 -F/Library/Frameworks
endif
ifeq ($(UNAME), Linux)
	CXX = g++
	SDL = -lSDL2 -lSDL2_ttf
	CXXFLAGS = -Wall -std=c++11
endif
LDFLAGS = $(SDL)
EXE = ml
BINDIR = bin
SRCDIR = src
OBJDIR = obj

CPP_FILES := $(wildcard src/*.cpp)
CPP_OBJ_FILES:=$(patsubst src/%.cpp,obj/%.cpp.o,$(CPP_FILES))

.PHONY: clean directories

all: directories bin/$(EXE)

directories: $(BINDIR) $(OBJDIR)

bin/$(EXE): $(CPP_OBJ_FILES)
	$(CXX) $^ $(LDFLAGS) -o $@

obj/%.cpp.o: src/%.cpp $(CPP_FILES)
	g++ $< -o $@ $(CXXFLAGS) -c

ifeq ($(OS),Windows_NT)
$(OBJDIR):
	mkdir -p $(OBJ_FOLDER)

$(BINDIR):
	mkdir -p $(BIN_FOLDER)

clean:
	del /q obj\*
	del $(BINDIR)\*.exe
else
$(OBJDIR):
	mkdir $(OBJDIR)

$(BINDIR):
	mkdir $(BINDIR)

clean:
	rm obj/*.o && rm $(BIN_FOLDER)/$(EXE)
endif

rebuild:
	make clean
	make

