
TARGET = test 
SRCS = $(wildcard *.c)
OBJS = $(SRCS:.c = .o)
CC = gcc
CXX = g++

INCLUDES = -I../algrithms/sort.h \

LIBS =-L../algrithms -lhtalg

CCFLAGS = -g -Wall

$(TARGET) : $(OBJS)
	$(CC) $^ $(CCFLAGS) -o $@ $(LIBS)

%.o : %.c
	$(CC) -c $< $(CCFLAGS) $(INCLUDES)

clean:
	rm *.o $(TARGET)
.PHONY:clean
