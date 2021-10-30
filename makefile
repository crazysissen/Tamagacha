CC = g++
CTARGET = *.cpp
CFLAGS = --std=c++17 
CDFLAGS = -g -O0 -Wall
CRFLAGS = -O2

DOUT = -o tamagacha-d.exe
ROUT = -o tamagacha.exe

BRANCH := $(shell git for-each-ref --format='%(objectname) %(refname:short)' refs/heads | awk "/^$$(git rev-parse HEAD)/ {print \$$2}")

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
