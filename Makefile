CXX = g++
CXXFLAGS = -std=c++23 -Wall -I. -MMD -MP

SRC = $(wildcard helper/*.cpp)
OBJ = $(SRC:helper/%.cpp=$(BUILD_DIR)/%.o)
DEP = $(OBJ:.o=.d)
BUILD_DIR = build

$(BUILD_DIR):
	mkdir -p $@

$(BUILD_DIR)/%.o: helper/%.cpp | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

-include $(DEP)

all: $(shell printf "euler%03d " {1..100})

euler%: solution/euler%.cpp $(OBJ) | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) $^ -o $(BUILD_DIR)/$@

default:
	@echo "Use 'make eulerXXX' where XXX is the problem number"

.PHONY: clean
clean:
	rm -rf $(BUILD_DIR)