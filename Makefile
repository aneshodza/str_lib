CUNIT_DIR ?= /opt/homebrew/opt/cunit
CUNIT_INCLUDE = -I$(CUNIT_DIR)/include
CUNIT_LIB = -L$(CUNIT_DIR)/lib -lcunit

CC = gcc
CFLAGS = -Wall -Wextra -g -Iinclude $(CUNIT_INCLUDE)
LDFLAGS = $(CUNIT_LIB)

SRC := $(wildcard src/*.c)
TEST_SRC := $(wildcard tests/*.c)

TARGET = out/executable
TEST_TARGET = out/test_executable

all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) $^ -o $@

test: $(TEST_SRC) src/str_lib.c
	$(CC) $(CFLAGS) $^ -o $(TEST_TARGET) $(LDFLAGS)
	./$(TEST_TARGET)

clean:
	rm -f $(TARGET) $(TEST_TARGET)

