CXX = g++
CXXFLAGS = -std=c++23 -Wall -I.

START ?= 1
END   ?= 100

SRC := $(wildcard helper/*.cpp)

ALL_EULERS := $(shell seq -w $(START) $(END))

all: $(ALL_EULERS:%=euler%)

euler%: solution/euler%.cpp $(SRC)
	$(CXX) $(CXXFLAGS) $^ -o $@

default:
	@echo "Use 'make eulerXXX' where XXX is the problem number"

.PHONY: clean
clean:
	rm -f ./euler*