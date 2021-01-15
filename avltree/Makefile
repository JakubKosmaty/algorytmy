CXX := g++
CFLAGS := -std=c++17 -Wall
LDFLAGS := -std=c++17 -Wall

.PHONY: all clean

all: main.out

main.out: main.o
main.o: main.cpp AVLTree.h

%.out: %.o
	$(CXX) $(LDFLAGS) -o $@ $^

%.o: %.cpp
	$(CXX) $(CFLAGS) -c -o $@ $<

clean:
	find . -name ".DS_Store" -delete; $(RM) *.o *.out
