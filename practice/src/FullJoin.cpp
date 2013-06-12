#include <iostream>
#include <string>
#include <vector>
#include "../include/FullJoin.h"
using namespace std;


Field1::Field1(int id, char* value) : id(id), value(value)
{ }

Field2::Field2(int id, char* value) : Field1(id, value)
{ }

FullJoin::FullJoin()
{
	this->fields1.push_back(Field1(0, "ZERO"));
	this->fields1.push_back(Field1(1, "ONE"));
	this->fields1.push_back(Field1(2, "TWO"));
	this->fields1.push_back(Field1(2, "two"));
	this->fields1.push_back(Field1(3, "THREE"));
	this->fields1.push_back(Field1(3, "three"));
	this->fields1.push_back(Field1(4, "FOUR"));
	this->fields1.push_back(Field1(5, "FIVE"));
	this->fields1.push_back(Field1(5, "five"));

	this->fields2.push_back(Field2(1, "ek"));
	this->fields2.push_back(Field2(2, "do"));
	this->fields2.push_back(Field2(2, "du"));
	this->fields2.push_back(Field2(3, "tray"));
	this->fields2.push_back(Field2(4, "char"));
	this->fields2.push_back(Field2(4, "chaar"));

	this->fullJoin();
	this->fields1.clear();
	this->fields2.clear();
}

void FullJoin::print (int id1, string value1, int id2, string value2)
{
	cout << id1 << ", ";
	cout << ((value1 == "") ? "NULL" : value1) << ", ";
	cout << id2 << ", ";
	cout << ((value2 == "") ? "NULL" : value2);
	cout << endl;
}

void FullJoin::fullJoin ()
{
	unsigned i = 0, j = 0, count = 0;

	while ((i < this->fields1.size()) && (j < this->fields2.size()))
	{
		if (this->fields1[i].id < this->fields2[j].id)
		{
			print (this->fields1[i].id, this->fields1[i].value, -1, "");
			i++;
		}
		else if (this->fields1[i].id > this->fields2[j].id)
		{
			if (count > 0)
			{
				j += count;
				count = 0;
			}
			else
			{
				print (-1, "", this->fields2[j].id, this->fields2[j].value);
				j++;
			}
		}
		else
		{
			count = 0;
			while ((j+count < this->fields2.size()) && (this->fields1[i].id == this->fields2[j+count].id))
			{
				print (this->fields1[i].id, this->fields1[i].value, this->fields2[j+count].id, this->fields2[j+count].value);
				count++;
			}
			i++;
		}
	}
	j += count;

	while (i < this->fields1.size())
	{
		print (this->fields1[i].id, this->fields1[i].value, -1, "");
		i++;
	}
	while (j < this->fields2.size())
	{
		print (-1, "", this->fields2[j].id, this->fields2[j].value);
		j++;
	}
}