.PHONY: default build test clean

CXX = g++
INCLUDE = -Iinclude
CXX_FLAGS = $(INCLUDE) -std=c++17 -g

default: test

# build
build: $(patsubst solutions/%.cpp, bin/%.out, $(wildcard solutions/*.cpp))

%.o: %.cpp $(wildcard include/*.h)
	$(CXX) $(CXX_FLAGS) -c $< -o $@
bin/%.out: solutions/%.o main.o | bin/
	$(CXX) $(CXX_FLAGS) $< main.o -o $@

bin/:
	mkdir -p bin

# run
test: build
	ls bin/ | xargs -I{} sh -c "echo '\e[32mRunning bin/{}\e[0m'; bin/{};"

# clean
clean:
	find . -name "*.o" -type f -delete
	find . -name "*.out" -type f -delete
	rm -rf bin

# misc
compile_flags.txt:
	echo $(CXX) $(CXX_FLAGS) | sed 's/ /\n/g' > compile_flags.txt
