/*
Number of chips to begin with: 444.

12 12
0 8 1 7 8 8 5 2 9 5 9 5
8 5 1 1 5 6 9 4 4 5 2 1
7 2 3 5 2 9 2 6 9 3 9 4
9 2 5 9 8 9 5 7 7 5 9 6
2 4 6 7 1 4 2 6 6 2 5 8
2 8 1 5 3 8 4 9 7 5 2 3
2 9 3 5 6 7 2 4 9 4 2 5
6 3 1 7 8 2 3 3 6 7 9 3
2 5 7 4 2 7 8 5 5 3 5 8
5 2 9 8 3 6 1 4 9 5 6 3
4 6 9 8 5 4 9 7 6 4 6 8
2 7 7 1 9 9 7 3 7 2 2 5
0 0
11 11
444

At each step, the cost of each step increases.
*/

#include<iostream>
#include<vector>
using namespace std;

struct Point
{
	unsigned row, col;

	bool operator== (const Point& other)
	{
		return row == other.row && col == other.col;
	}
};

class IncrementingChipMap
{
private:
	unsigned rows, cols;
	vector<vector<unsigned>> map;
	vector<Point> solution;
	Point end;

	bool findPathFrom(Point start, int level, int totalToSpend)
	{
		if (start == end)
		{
			if (totalToSpend == 0)
				return true;
		}

		if (totalToSpend <= 0)
			return false;

		this->solution.push_back(start);

		Point top = start, left = start, right = start, bottom = start;
		top.row--; left.col--; right.col++; bottom.row++;

		bool result = false;
		if (!result && top.row < this->rows)
		{
			unsigned thisValue = this->map[top.row][top.col];
			int newTotal = totalToSpend - thisValue - level;
			if (top == end) newTotal += level;
			result = this->findPathFrom(top, level + 1, newTotal);
		}
		if (!result && left.col < this->cols)
		{
			unsigned thisValue = this->map[left.row][left.col];
			int newTotal = totalToSpend - thisValue - level;
			if (left == end) newTotal += level;
			result = this->findPathFrom(left, level + 1, newTotal);
		}
		if (!result && right.col < this->cols)
		{
			unsigned thisValue = this->map[right.row][right.col];
			int newTotal = totalToSpend - thisValue - level;
			if (right == end) newTotal += level;
			result = this->findPathFrom(right, level + 1, newTotal);
		}
		if (!result && bottom.row < this->rows)
		{
			unsigned thisValue = this->map[bottom.row][bottom.col];
			int newTotal = totalToSpend - thisValue - level;
			if (bottom == end) newTotal += level;
			result = this->findPathFrom(bottom, level + 1, newTotal);
		}

		if (!result)
		{
			this->solution.pop_back();
		}

		return result;
	}

public:
	IncrementingChipMap()
	{
		cin >> this->rows;
		cin >> this->cols;

		unsigned i, j;
		for (i = 0; i < this->rows; i++)
		{
			vector<unsigned> oneRow;
			for (j = 0; j < this->cols; j++)
			{
				unsigned cost;
				cin >> cost;
				oneRow.push_back(cost);
			}
			this->map.push_back(oneRow);
		}

		Point start;
		cin >> start.row >> start.col;
		cin >> this->end.row >> this->end.col;

		int totalToSpend;
		cin >> totalToSpend;
		if (this->findPathFrom(start, 0, totalToSpend))
		{
			cout << this->solution[0].row << endl;
		}
	}
};

int main (int argc, char** argv)
{
	IncrementingChipMap* incrementingChipMap = new IncrementingChipMap;
	delete incrementingChipMap;
	return 0;
}