CFLAGS=-std=c11 -g -static
SRCS=$(wildcard *.c)
OBJS=$(SRCS:.c=.o)

ucc: $(OBJS)
	$(CC) -o ucc $(OBJS) $(CFLAGS)

$(OBJS: ucc.h)

test: ucc
	./test.sh

clean:
	rm -f ucc *.o *~ tmp*

.PHONY: test clean
