CXX = g++
CXXFLAGS = -std=c++23 -Wall -I.

SRC = $(wildcard helper/*.cpp)
BUILD_DIR = build

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

all: $(addprefix euler,$(shell seq -w 1 100))

euler%: solution/euler%.cpp $(SRC) | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) $^ -o $(BUILD_DIR)/$@

default:
	@echo "Use 'make eulerXXX' where XXX is the problem number"

.PHONY: clean
clean:
	rm -rf $(BUILD_DIR)