CC=gcc

CFLAGS= -Wall -pedantic -gdwarf-2 -fno-inline -fno-omit-frame-pointer
OBJ = src/main.c

%.o: %.c 
	$(CC) -c -o $@ $< $(CFLAGS)

prisoners: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

clean:
	rm -f prisoners *.o
