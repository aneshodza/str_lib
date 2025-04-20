
# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -g

# Executable name
TARGET = executable

SRCS = main.c str_lib.c
OBJS = $(SRCS:.c=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)
