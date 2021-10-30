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

g_commit:
	git add .
	git commit -m "$m"

g_push:
	make g_commit -m m="$m"
	git push -u origin $(BRANCH)

g_pull:
	git fetch
	git merge

g_buildMain-d:
	make g_commit -m m="$m"
	git checkout main
	make g_pull
	make debug

g_buildMain:
	make g_commit -m m="$m"
	git checkout main
	make g_pull
	make release