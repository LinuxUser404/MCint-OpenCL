

CC = g++
OPTS = -Wall -O2
PROGS = mcint-ocl


INCLUDE = -I.
SRC = -L.
LIBRARY =  -lOpenCL

all: $(PROGS)

mcint-ocl:
	$(CC) $(OPTS) -o mcint-ocl mcint-ocl.cpp $(INCLUDE) $(LIBRARY)
	
	
clean:
	rm -f *.o $(PROGS)

test: mcint-ocl
	./mcint-ocl
