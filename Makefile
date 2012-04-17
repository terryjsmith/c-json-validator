
CC := g++
CFLAGS=-Wall -g -I./ -I./jsoncpp/include

# Link command:
json-parser: main.o jsoncpp/src/lib_json/json_reader.o jsoncpp/src/lib_json/json_value.o jsoncpp/src/lib_json/json_writer.o
	$(CC) $(CFLAGS) $^ -o $@

# Individual files    
%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

# Build both
all: json-parser

clean:
	rm *.o
