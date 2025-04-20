
# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -g

# Executable name
TARGET = out/executable

SRCS := $(wildcard src/*.c)
OBJS = $(SRCS:.c=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)
