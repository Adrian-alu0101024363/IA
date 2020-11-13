all: main.cpp node.cpp zone.cpp astar.cpp

CXX=g++
CXXFLAGS=-g -w

OBJS = main.o node.o zone.o astar.o


all: ${OBJS}
	$(CXX) $(CXXFLAGS) -o astar ${OBJS}

clean:
	rm -rf *.o astar