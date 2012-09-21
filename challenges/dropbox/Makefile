CC=g++
STRIP=strip
CFLAGS=-c -O3 #-Wall
LDFLAGS=

CPP_FILES := $(wildcard *.cpp)
OBJ_FILES := $(addprefix ,$(notdir $(CPP_FILES:.cpp=.o)))
EXECUTABLE=hoppity

all: $(SOURCES) $(EXECUTABLE) strip

clean:
	rm -rf *.o $(EXECUTABLE)

strip:
	$(STRIP) $(EXECUTABLE)

$(EXECUTABLE): $(OBJ_FILES)
	$(CC) $(LDFLAGS) $(OBJ_FILES) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@
