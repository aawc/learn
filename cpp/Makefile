all: string this_ptr unique_ptr unordered_map vector

clean:
	$(RM) string this_ptr unique_ptr unordered_map vector

string: string.o
		g++ -g3 -o string string.o

string.o: string.cc
		g++ -g3 -std=c++11 -c  string.cc

this_ptr: this_ptr.o
		g++ -g3 -o this_ptr this_ptr.o

this_ptr.o: this_ptr.cc
		g++ -g3 -std=c++11 -c  this_ptr.cc

unique_ptr: unique_ptr.o
		g++ -g3 -o unique_ptr unique_ptr.o

unique_ptr.o: unique_ptr.cc
		g++ -g3 -std=c++11 -c  unique_ptr.cc

unordered_map: unordered_map.o
		g++ -g3 -o unordered_map unordered_map.o

unordered_map.o: unordered_map.cc
		g++ -g3 -std=c++11 -c  unordered_map.cc

vector: vector.o
		g++ -g3 -o vector vector.o

vector.o: vector.cc
		g++ -g3 -std=c++11 -c  vector.cc

