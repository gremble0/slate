CC=g++
CFLAGS=-Wall -Wextra
LINKS=`pkg-config --cflags --libs gtkmm-4.0`
SRC=src/

all:
	$(CC) $(SRC)main.cpp -o slate $(CFLAGS) $(LINKS)

clean:
	rm -f main
