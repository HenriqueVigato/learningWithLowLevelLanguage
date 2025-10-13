CC = gcc
CFLAGS = -Wall -Wextra -g
UNITY = ../Unity/src

test: test.c ../read.c $(UNITY)/unity.c
	$(CC) $(CFLAGS) -DTESTING -I$(UNITY) $^ -o $@
	./test

clean:
	rm -f test
