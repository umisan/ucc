CFLAGS=-std=c11 -g -static

ucc: ucc.c

test: ucc
	./test.sh

clean:
	rm -f 9cc *.o *~ tmp*

.PHONY: test clean
