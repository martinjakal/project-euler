CXX = g++
CXXFLAGS = -std=c++23 -Wall -I. -MMD -MP

START ?= 1
END   ?= 100

SRC = $(wildcard helper/*.cpp)
OBJ = $(SRC:helper/%.cpp=$(BUILD_DIR)/%.o)
DEP = $(OBJ:.o=.d)
BUILD_DIR = build

$(BUILD_DIR):
	mkdir -p $@

$(BUILD_DIR)/%.o: helper/%.cpp | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

-include $(DEP)

all: $(shell seq -f "euler%03g" $(START) $(END))

euler%: solution/euler%.cpp $(OBJ) | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) $^ -o $(BUILD_DIR)/$@

default:
	@echo "Use 'make eulerXXX' where XXX is the problem number"

.PHONY: clean
clean:
	rm -rf $(BUILD_DIR)