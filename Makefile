CC = gcc
CFLAGS  = -Wall -Werror
OBJS = resh.o resh_input.o resh_execute.o
VPATH = src:

all: dependencies resh
	rm deps

resh: $(OBJS)

dependencies:
	$(CC) -MM src/*.c > deps
-include deps

.PHONY: dependencies clean

clean:
	rm *.o resh