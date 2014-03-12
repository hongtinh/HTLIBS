
TARGET = libhtalg.so
SRCS = $(wildcard *.c)
OBJS = $(SRCS:.c = .o)
CC = gcc
CXX = g++

INCLUDES = -I./sort.h \

LIBS = 

CCFLAGS = -g -Wall -fPIC 

$(TARGET) : $(OBJS)
	$(CC) $^ $(CCFLAGS) -shared -o $@ $(LIBS)

%.o : %.c
	$(CC) -c $< $(CCFLAGS) $(INCLUDES)

clean:
	rm *.o
.PHONY:clean
