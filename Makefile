.POSIX:
CC		= cc
CFLAGS		= -I/usr/local/include --std=c99 -g -Wall -Werror
LDFLAGS		= -L/usr/local/lib -lmenu -lncurses
BIN		= sine
VERSION		= 1.0

all: io.o main.o
	$(CC) $(CFLAGS) $> -o $(BIN) $(LDFLAGS)

main.o: main.c io.h
	$(CC) $(CFLAGS) -c $< -o $@

io.o: io.c data.h
	$(CC) $(CFLAGS) -c $< -o $@

release: all
	strip -s $(BIN)

hash:
	sha256 -h SHA256 *.c *.h LICENSE README Makefile

dist:
	tar -czf sine-$(VERSION).tar.gz LICENSE Makefile README SHA256 *.c *.h
	sha256 -h SHA256-$(VERSION) sine-$(VERSION).tar.gz

clean:
	rm *.o $(BIN)
