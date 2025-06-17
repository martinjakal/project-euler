CXX = g++
CXXFLAGS = -std=c++23 -Wall -I.

SRC := $(wildcard helper/*.cpp)

euler%: solution/euler%.cpp $(SRC)
	$(CXX) $(CXXFLAGS) $^ -o $@

default:
	@echo "Use 'make eulerXXX' where XXX is the problem number"

.PHONY: clean
clean:
	rm -f ./euler*