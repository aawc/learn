CC=g++
STRIP=strip
CFLAGS=-c -O3
LDFLAGS=
SOURCES=meepmeep.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=meepmeep

all: $(SOURCES) $(EXECUTABLE) strip

clean:
	rm -rf *.o $(EXECUTABLE)

strip:
	$(STRIP) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@
