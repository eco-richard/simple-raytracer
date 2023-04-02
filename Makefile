CXX=g++
CXXFLAGS=-Wall -g --std=c++20

BIN=./bin

all: main make-ppm

main: main.cc R3Vector.h Ray.h
	$(CXX) $(CXXFLAGS) main.cc -o $(BIN)/main 

make-ppm: $(BIN)/main
	$(BIN)/main >> main.ppm

clean:
	rm -rf *.o $(BIN)/*.dSYM *.ppm

