CC = g++
CTARGET = *.cpp
CFLAGS = --std=c++17 
CDFLAGS = -g -O0 -Wall
CRFLAGS = -O2

DOUT = -o tamagacha-d.exe
ROUT = -o tamagacha.exe

debug:
	$(CC) $(CTARGET) $(CDFLAGS) $(DOUT) $(CFLAGS)

release:
	$(CC) $(CTARGET) $(CRFLAGS) $(ROUT) $(CFLAGS)
