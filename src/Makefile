CC=g++
CFLAGS=-Wall -Wextra -Isrc
LINKS=`pkg-config --cflags --libs gtkmm-4.0`
BUILD=build/
OBJS=$(addprefix $(BUILD), SlateBuffer.o Slate.o)

dir_guard=@mkdir -p $(BUILD)

all: slate

slate: $(OBJS)
	$(CC) $(CFLAGS) $(LINKS) $(OBJS) -o slate 

$(BUILD)Slate.o: $(addprefix $(BUILD), SlateBuffer.o) ui.hpp
	$(dir_guard)
	$(CC) $(CFLAGS) $(LINKS) -c Slate.cpp -o $(BUILD)Slate.o

$(BUILD)SlateBuffer.o: SlateBuffer.cpp SlateBuffer.hpp
	$(dir_guard)
	$(CC) $(CFLAGS) $(LINKS) -c SlateBuffer.cpp -o $(BUILD)SlateBuffer.o

clean:
	rm -f slate $(OBJS)
