CFLAGS = -g -Wall
CXX = g++

objects = myshell.o param.o parse.o

myshell: $(objects)
	$(CXX) -o myshell $(objects)

myshell.o: myshell.cpp parse.hpp param.hpp
param.o: param.cpp param.hpp
parse.o: parse.cpp parse.hpp param.hpp

.PHONY : clean
clean:
	rm test $(objects)
