#include <iostream>
#include <string>
#include <vector>
#include "../include/FullJoin.h"
using namespace std;


Field1::Field1(int id, char* value) : id(id), value(value)
{ }

Field2::Field2(int id, char* value) : id(id), value(value)
{ }

void print (int id1, string value1, int id2, string value2)
{
	cout << id1 << ", ";
	cout << ((value1 == "") ? "NULL" : value1) << ", ";
	cout << id2 << ", ";
	cout << ((value2 == "") ? "NULL" : value2);
	cout << endl;
}

void fullJoin (vector<Field1> fields1, vector<Field2> fields2)
{
	unsigned i = 0, j = 0, count = 0;

	while ((i < fields1.size()) && (j < fields2.size()))
	{
		if (fields1[i].id < fields2[j].id)
		{
			print (fields1[i].id, fields1[i].value, -1, "");
			i++;
		}
		else if (fields1[i].id > fields2[j].id)
		{
			if (count > 0)
			{
				j += count;
				count = 0;
			}
			else
			{
				print (-1, "", fields2[j].id, fields2[j].value);
				j++;
			}
		}
		else
		{
			count = 0;
			while ((j+count < fields2.size()) && (fields1[i].id == fields2[j+count].id))
			{
				print (fields1[i].id, fields1[i].value, fields2[j+count].id, fields2[j+count].value);
				count++;
			}
			i++;
		}
	}
	j += count;

	while (i < fields1.size())
	{
		print (fields1[i].id, fields1[i].value, -1, "");
		i++;
	}
	while (j < fields2.size())
	{
		print (-1, "", fields2[j].id, fields2[j].value);
		j++;
	}
}

/*
int main (int argc, char** argv)
{
	std::vector<Field1> fields1 = {{0, "ZERO"}, {1, "ONE"}, {2, "TWO"}, {2, "two"}, {3, "THREE"}};
	std::vector<Field1> fields2 = {{1, "ek"}, {2, "do"}, {2, "du"}, {3, "tray"}, {4, "char"}};

	fullJoin(fields1, fields2);
	return 0;
}
*/