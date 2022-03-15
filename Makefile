CXX = g++
DEPS = ChaCha.hpp
OBJ = ChaCha.o main.o

%.o: %.cpp $(DEPS)
	$(CXX) -c -o $@ $<

main: $(OBJ)
	$(CXX) -o $@ $^

clean:
	rm *.o main

objects:
