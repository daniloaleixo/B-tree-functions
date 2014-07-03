CC = gcc
CFLAGS = -Wall -ansi -pedantic -O2 -g
LFLAGS = -lm
OUT = ep4
IN = ep4.c
OBJS = ep4.o


all: $(OUT)

clean: 
	rm -f $(OBJS) $(OUT)

$(OUT): $(OBJS) 
	$(CC) $(OBJS) $(CFLAGS) -o $(OUT)

ep4.o: $(IN)
	$(CC) $(IN) $(CFLAGS) -c -o ep4.o

StringOps.o: StringOps.c
	$(CC) StringOps.c $(CFLAGS) -c -o StringOps.o

