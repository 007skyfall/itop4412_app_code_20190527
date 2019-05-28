src = $(wildcard *.c)
targets = $(patsubst %.c, %, $(src))

CC = gcc
STRIP=strip
CFLAGS = -Wall -g -D_GNU_SOURCE

all:$(targets)

$(targets):%:%.c
	$(CC) $< -o $@ $(CFLAGS)
	$(STRIP) $@

.PHONY:clean all
clean:
	-rm -rf $(targets)
