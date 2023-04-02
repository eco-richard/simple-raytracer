CXX=g++
CXXFLAGS=-Wall -g --std=c++20

BIN=./bin
HDRS=*.h

all: main make-ppm

main: main.cc $(HDRS)
	$(CXX) $(CXXFLAGS) main.cc -o $(BIN)/main 

make-ppm: $(BIN)/main
	$(BIN)/main >> main.ppm

clean:
	rm -rf *.o $(BIN)/*.dSYM *.ppm

