// http://www.facebook.com/careers/puzzles.php?puzzle_id=7

using namespace std;

#include <iostream>
#include <fstream>
#include <limits.h>

#define DIV_BY_3 "Hoppity"
#define DIV_BY_5 "Hophop"
#define THREE_AND_FIVE "Hop"

int main (int argc, char *argv[])
{
	if (2 != argc) {
		return __LINE__;
	}

	char *filename = argv[1];
	ifstream fin (filename);
	int n;
	fin >> n;
	for (int i = 1; i <= n; i++) {
		bool isDivBy3 = (0 == i%3);
		bool isDivBy5 = (0 == i%5);
		if (isDivBy3 && isDivBy5) {
			cout << THREE_AND_FIVE << endl;
		} else if (isDivBy3) {
			cout << DIV_BY_3 << endl;
		} else if (isDivBy5) {
			cout << DIV_BY_5 << endl;
		}
	}
}
