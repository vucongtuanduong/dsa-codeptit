# COMP2521 - Week 5 Lab

# !!! DO NOT MODIFY THIS FILE !!!

CC = g++
CFLAGS = -Wall -Wvla -Werror -g

########################################################################

.PHONY: asan msan nosan

asan: CFLAGS += -fsanitize=address,leak,undefined
asan: all

msan: CFLAGS += -fsanitize=memory,undefined -fsanitize-memory-track-origins
msan: all

nosan: all

########################################################################

.PHONY: all
all: ctdl001.exe

ctdl001.exe: ctdl001.o
	$(CC) $(CFLAGS) -o ctdl001.exe ctdl001.o

ctdl001.o: ctdl001.cpp

.PHONY: clean
clean:
	rm -f *.o ctdl001.exe