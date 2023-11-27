CC=g++
CFLAGS=-Wall -Wextra -Isrc
LINKS=`pkg-config --cflags --libs gtkmm-4.0`
BUILD=build/
OBJS=$(addprefix $(BUILD), SlateBuffer.o SlateWindow.o main.o)

dir_guard=@mkdir -p $(BUILD)

all: slate

slate: $(OBJS)
	$(CC) $(CFLAGS) $(LINKS) $(OBJS) -o slate 

$(BUILD)main.o: $(addprefix $(BUILD), SlateBuffer.o SlateWindow.o) ui.hpp
	$(dir_guard)
	$(CC) $(CFLAGS) $(LINKS) -c main.cpp -o $(BUILD)main.o

$(BUILD)SlateWindow.o: $(BUILD)SlateBuffer.o SlateWindow.hpp
	$(dir_guard)
	$(CC) $(CFLAGS) $(LINKS) -c SlateWindow.cpp -o $(BUILD)SlateWindow.o

$(BUILD)SlateBuffer.o: SlateBuffer.cpp SlateBuffer.hpp
	$(dir_guard)
	$(CC) $(CFLAGS) $(LINKS) -c SlateBuffer.cpp -o $(BUILD)SlateBuffer.o

clean:
	rm -f slate $(OBJS)
