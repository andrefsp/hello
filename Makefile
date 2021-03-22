PROJECT_DIR:=$(shell dirname $(realpath $(firstword $(MAKEFILE_LIST))))

# testing.
TEST_DIR=./test
TEST_BIN=$(TEST_DIR)/bin
TEST_TARGET=$(TEST_BIN)/test

# testing.
EXAMPLE_DIR=./example
EXAMPLE_BIN=$(EXAMPLE_DIR)/bin
EXAMPLE_TARGET=$(EXAMPLE_BIN)/example


# pkg-config
PKG_CONFIG=$$(pkg-config --cflags --libs bdw-gc,libcurl,libuv)


INCLUDE=-I$(PROJECT_DIR)/src/includes -I$(PROJECT_DIR)/src


CC=gcc -Wall -x c -std=gnu18 $(PKG_CONFIG) -ldl -lpthread $(INCLUDE)


build:
	$(CC) -o libhello.so -fPIC -c ./src/hello.c


# commands:
clean:
	mkdir -p $(TEST_BIN); rm -rf $(TEST_BIN)/*
	mkdir -p $(EXAMPLE_BIN); rm -rf $(EXAMPLE_BIN)/*


# commands: c testing
compile-test: clean
	$(CC) $(TEST_DIR)/test.c -o $(TEST_TARGET)


run-test: compile-test
	$(TEST_TARGET)



# commands: c example
compile-example: clean build
	$(CC) -L$(PROJECT_DIR) -lhello -g $(EXAMPLE_DIR)/main.c -o $(EXAMPLE_TARGET)


run-example: clean compile-example
	$(EXAMPLE_TARGET)
