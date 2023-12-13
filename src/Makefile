CC=g++
CFLAGS=-Wall -Wextra -Isrc -I../lib/sol2/include -llua
LINKS=`pkg-config --cflags --libs gtkmm-4.0`
BUILD=build/
OBJS=$(addprefix $(BUILD), Cursor.o Buffer.o Window.o main.o)

dir_guard=@mkdir -p $(BUILD)

all: slate

slate: $(OBJS)
	$(CC) $(CFLAGS) $(LINKS) $(OBJS) -o slate 

$(BUILD)main.o: $(addprefix $(BUILD), Buffer.o Window.o)
	$(dir_guard)
	$(CC) $(CFLAGS) $(LINKS) -c main.cpp -o $(BUILD)main.o

$(BUILD)Window.o: $(BUILD)Buffer.o Window.hpp
	$(dir_guard)
	$(CC) $(CFLAGS) $(LINKS) -c Window.cpp -o $(BUILD)Window.o

$(BUILD)Buffer.o: $(BUILD)Cursor.o Buffer.cpp Buffer.hpp
	$(dir_guard)
	$(CC) $(CFLAGS) $(LINKS) -c Buffer.cpp -o $(BUILD)Buffer.o

$(BUILD)Cursor.o: Cursor.hpp
	$(dir_guard)
	$(CC) $(CFLAGS) $(LINKS) -c Cursor.cpp -o $(BUILD)Cursor.o

clean:
	rm -f slate $(OBJS)
