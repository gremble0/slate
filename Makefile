CC=g++
CFLAGS=-Wall -Wextra
LINKS=`pkg-config --cflags --libs gtkmm-4.0`

all:
	$(CC) main.cpp -o slate $(CFLAGS) $(LINKS)

clean:
	rm -f main
