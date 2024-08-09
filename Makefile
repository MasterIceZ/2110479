CXX=clang++
CFXXLAGS=-Wno-macro-redefined -Wall
LDFLAGS=-L$(BREW_PREFIX)/lib -lglfw -framework OpenGL -DGL_SILENCE_DEPRECATION

BREW_PREFIX=$(shell brew --prefix)
PROJ_DIR=$(CURDIR)

TARGET=build/main

INCLUDES=-I$(BREW_PREFIX)/include -I$(PROJ_DIR)/include

SRC = $(shell find src -name '*.cpp' -o -name '*.c')

all:
	$(CXX) -o $(TARGET) $(SRC) $(INCLUDES) $(LDFLAGS) $(CFXXLAGS)
clean:
	$(RM) $(TARGET)
