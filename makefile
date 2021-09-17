CC = g++
CFLAGS = --std=c++17 
CDFLAGS = -g -O0 -Wall
CRFLAGS = -O2

DOUT = -o tamagacha-d.exe
ROUT = -o tamagacha.exe

debug:
	$(CC) $(CDFLAGS) $(DOUT) $(CFLAGS)

release:
	$(CC) $(CRFLAGS) $(ROUT) $(CFLAGS)
