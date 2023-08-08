CC = gcc 
CFLAGS = -Wall -Wextra -I.

wish: wish.o
	$(CC) $(CFLAGS) -o wish wish.o

clean:
	rm -rf *.o wish
