all: main

CC = gcc
override CFLAGS += -g -Wno-everything -pthread -lm

SRCS = $(shell find . -name '.ccls-cache' -type d -prune -o -type f -name '*.c' -print)
HEADERS = $(shell find . -name '.ccls-cache' -type d -prune -o -type f -name '*.h' -print)

main: $(SRCS) $(HEADERS)
	@$(CC) $(CFLAGS) $(SRCS) -o "$@" -lm
	@echo "Compilado!"

main-debug: $(SRCS) $(HEADERS)
	@$(CC) $(CFLAGS) -O0 $(SRCS) -o "$@" -lm
	@echo "Debug Compilado!"

clean:
	rm -f main main-debug