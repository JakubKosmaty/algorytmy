CXX := g++
LDFLAGS := -Wall -std=c++17
CFLAGS := -Wall -std=c++17
OBJECTS := main.o
SRCS := $(patsubst %.o,%.h,$(OBJECTS))
TARGET := main.out

%.o: %.cpp $(SRCS)
	$(CXX) $(LDFLAGS) -c $< -o $@

$(TARGET): $(OBJECTS)
	$(CXX) $(CFLAGS) $(LIBS) $(OBJECTS) -o $(TARGET)

.PHONY: clean

clean:
	find . -name ".DS_Store" -delete; $(RM) *.o *.out