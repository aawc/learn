#ifndef __FULLJOIN_H__
#define __FULLJOIN_H__

#include <string>
#include <vector>
using namespace std;

struct Field1
{
	int id;
	string value;

	Field1(int id, char* value);
};

struct Field2 : Field1
{
	Field2(int id, char* value);
};

class FullJoin
{
private:
	vector<Field1> fields1;
	vector<Field2> fields2;

public:
	FullJoin();
	void print (int id1, string value1, int id2, string value2);
	void fullJoin ();
};

#endif //__FULLJOIN_H__