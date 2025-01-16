CXX = g++
CXXFLAGS = -Wall -std=c++17 -I/opt/homebrew/Cellar/raylib/5.5/include
LDFLAGS = -L/opt/homebrew/Cellar/raylib/5.5/lib -lraylib -lm -ldl -lpthread

all: main

main: main.cpp
	$(CXX) $(CXXFLAGS) main.cpp PPM.cpp renderer.cpp -o main $(LDFLAGS)

clean:
	rm -f ppm
