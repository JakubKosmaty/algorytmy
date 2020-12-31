CXX := g++
CFLAGS := -std=c++17 -Wall
LDFLAGS := -std=c++17 -Wall
CPPFLAGS := -Iinclude -MMD -MP
SRC_DIR := src
EXE := maze_generator.out
SRC := $(wildcard $(SRC_DIR)/*.cpp)
OBJ := $(SRC:$(SRC_DIR)/%.cpp=%.o)

.PHONY: all clean

all: $(EXE)

$(EXE): $(OBJ)
	$(CXX) $(LDFLAGS) $^ -o $@

%.o: $(SRC_DIR)/%.cpp
	$(CXX) $(CPPFLAGS) $(CFLAGS) -c $< -o $@

clean:
	find . -name ".DS_Store" -delete; $(RM) *.out *.o *.d

-include $(OBJ:.o=.d)