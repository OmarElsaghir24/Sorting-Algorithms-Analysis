CC = gcc
CFLAGS = -Wall -Wextra -std=c11 -g
GTK_FLAGS = $(shell pkg-config --cflags gtk4)
GTK_LIBS = $(shell pkg-config --libs gtk4)

COMMON_SRC = menu_features.c sorting_algorithms.c utilities.c
COMMON_OBJ = $(COMMON_SRC:.c=.o)

CONSOLE_SRC = main.c
CONSOLE_OBJ = $(CONSOLE_SRC:.c=.o)

.PHONY: all console clean

all: console

console: console_app

console_app: $(COMMON_OBJ) $(CONSOLE_OBJ)   
	$(CC) $(CFLAGS) -o $@ $(COMMON_OBJ) $(CONSOLE_OBJ) $(GTK_LIBS)  

%.o: %.c
	$(CC) $(CFLAGS) $(GTK_FLAGS) -c $< -o $@

clean:
	rm -f *.o console_app