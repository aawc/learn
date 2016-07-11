all: string unique_ptr vector

clean:
	$(RM) string unique_ptr vector

string: string.o
		g++ -g -o string string.o

string.o: string.cc
		g++ -g -std=c++11 -c  string.cc

unique_ptr: unique_ptr.o
		g++ -g -o unique_ptr unique_ptr.o

unique_ptr.o: unique_ptr.cc
		g++ -g -std=c++11 -c  unique_ptr.cc

vector: vector.o
		g++ -g -o vector vector.o

vector.o: vector.cc
		g++ -g -std=c++11 -c  vector.cc

