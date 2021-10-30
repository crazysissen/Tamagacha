CC = g++
CTARGET = *.cpp
CFLAGS = --std=c++17 
CDFLAGS = -g -O0 -Wall
CRFLAGS = -O2

DOUT = -o tamagacha-d.exe
ROUT = -o tamagacha.exe

BRANCH := $(shell git rev-parse --abrev-ref HEAD)

debug:
	$(CC) $(CTARGET) $(CDFLAGS) $(DOUT) $(CFLAGS)

release:
	$(CC) $(CTARGET) $(CRFLAGS) $(ROUT) $(CFLAGS)

g_push:
	git add .
	git commit -m "$m"
	git push -u origin $(BRANCH)

g_pull:
	git fetch
	gitMerge
