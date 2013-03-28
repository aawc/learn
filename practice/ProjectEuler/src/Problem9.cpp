/*
 * A Pythagorean triplet is a set of three natural numbers, a  b  c, for which, a2 + b2 = c2.
 * For example, 32 + 42 = 9 + 16 = 25 = 52.
 * There exists exactly one Pythagorean triplet for which a + b + c = 1000. Find the product a*b*c.
 */

#include "../include/Problem9.h"
#include <iostream>
#include <string>
using namespace std;

Problem9::Problem9()
{
}

Problem9::~Problem9()
{
}

Problem9::Problem9(const Problem9& other)
{
}

Problem9& Problem9::operator=(const Problem9& other)
{
	if (this == &other) return *this; // handle self assignment
	return *this;
}

int Problem9::getSpecialPythagoreanTriplet()
{
    int product = 1;
	for (int a = 1; a < 998; a++)
	{
		for (int b = 1; a+b < 1000; b++)
		{
			for (int c = 1; a+b+c <= 1000; c++)
			{
			    if (a + b + c != 1000)
                {
                    continue;
                }

				if (a*a + b*b == c*c)
				{
					cout << "Triplet: " << a << ", " << b << ", " << c << endl;
					product = a * b * c;
				}
				else if (c*c + a*a == b*b)
				{
					cout << "Triplet: " << c << ", " << a << ", " << b << endl;
					product = a * b * c;
				}
				else if (b*b + c*c == a*a)
				{
					cout << "Triplet: " << b << ", " << c << ", " << a << endl;
					product = a * b * c;
				}
			}
		}
	}

	return product;
}
