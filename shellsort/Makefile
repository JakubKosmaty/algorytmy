CXX := g++
CFLAGS := -std=c++17 -Wall
LDFLAGS := -std=c++17 -Wall

.PHONY: all clean

all: main.out shellSort.o

main.out: main.o shellSort.o
main.o: main.cpp shellSort.h

shellSort.o: shellSort.cpp

%.out: %.o
	$(CXX) $(LDFLAGS) -o $@ $^

%.o: %.cpp
	$(CXX) $(CFLAGS) -c -o $@ $<

clean:
	find . -name ".DS_Store" -delete; $(RM) *.o *.out
