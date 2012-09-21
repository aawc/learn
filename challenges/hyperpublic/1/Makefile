CC=g++
STRIP=strip
CFLAGS=-c -O3 #-Wall
LDFLAGS=
SOURCES=hoppity.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=hoppity

all: $(SOURCES) $(EXECUTABLE) strip

clean:
	rm -rf *.o $(EXECUTABLE)

strip:
	$(STRIP) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@
