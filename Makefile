

CC = g++
OPTS = -Wall -O2
PROGS = mcint-ocl

INCLUDE = -I. -I/usr/local/cuda-7.5/include/
SRC = -L.
LIBRARY =  -lOpenCL
LIBRARYPATH = -L/usr/local/cuda-7.5/lib64

all: $(PROGS)

mcint-ocl:
        $(CC) $(OPTS) -o mcint-ocl mcint-ocl.cpp $(INCLUDE) $(LIBRARYPATH) $(LIBRARY)
        
        
clean:
        rm -f *.o $(PROGS)

test: mcint-ocl
        ./mcint-ocl
