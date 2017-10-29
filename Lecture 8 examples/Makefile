CC = gcc
CFLAGS = -Os -c -fPIC

SOURCES1 := ex1.c
OBJECTS1 := $(SOURCES1:.c=.o)
SOURCES2 := ex2.c
OBJECTS2 := $(SOURCES2:.c=.o)
SOURCES3 := ex3.c
OBJECTS3 := $(SOURCES3:.c=.o)
SOURCES4 := ex4.c
OBJECTS4 := $(SOURCES4:.c=.o)
SOURCES5 := ex5.c
OBJECTS5 := $(SOURCES5:.c=.o)

all: ex1
	make ex1
	make ex2
	make ex3
	make ex4
	make ex5
	make clean

ex1: $(OBJECTS1)
	$(CC) -o $@ $(OBJECTS1)
ex2: $(OBJECTS2)
	$(CC) -o $@ $(OBJECTS2) -lpthread
ex3: $(OBJECTS3)
	$(CC) -o $@ $(OBJECTS3) -lpthread
ex4: $(OBJECTS4)
	$(CC) -o $@ $(OBJECTS4) -lpthread
ex5: $(OBJECTS5)
	$(CC) -o $@ $(OBJECTS5) -lpthread

%.o: %.c header.h
	$(CC) $(CFLAGS) -o $@ $<

clean:
	rm -f $(OBJECTS1) $(OBJECTS2) $(OBJECTS3) $(OBJECTS4) $(OBJECTS5)

.PHONY: clean all
