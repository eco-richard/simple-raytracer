CXX=g++
CXXFLAGS=-Wall -g --std=c++20

BIN=./bin

all: main make-ppm

main: main.cc
	$(CXX) $(CXXFLAGS) main.cc -o $(BIN)/main

make-ppm: $(BIN)/main
	$(BIN)/main >> main.ppm

R3Vector.o: R3Vector.cc
	$(CXX) $(CXXFLAGS) -c R3Vector.cc

clean:
	rm -rf *.o $(BIN)/*.dSYM

