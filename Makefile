SOURCES = $(wildcard *.c)
OBJECTS = $(SOURCES:.c=.o)
EXEC = 2048
CC=gcc

%.o: %.c
	$(CC) -c $^ -o $@

grid: $(OBJECTS)
	mv $^ ..

movements: $(OBJECTS)
	mv $^ ..

src: main.c
	$(CC) -c $^ -o main.o
	
$(EXEC): 
	$(CC) *.o -o $@

clean: 
	rm -r bin 2048