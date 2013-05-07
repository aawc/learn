/*
Datacenter Cooling
We have some rooms in our datacenter, and we need to connect them all with a single cooling duct.

Here are the rules:
The datacenter is represented by a 2D grid.
Rooms we own are represented by a 0.
Rooms we do not own are represented by a 1.
The duct has to start at the air intake valve, which is represented by a 2.
The duct has to end at the air conditioner, which is represented by a 3.
The duct cannot go in multiple directions out of the intake or the AC - they must be the two endpoints of the duct.
The duct must pass through each room exactly once.
The duct cannot pass through rooms we do not own.
The duct can connect between rooms horizontally or vertically but not diagonally.

Here is an example datacenter:

1
2
3
4
5
2  0  0  0

0  0  0  0

0  0  3  1

There are two possible ways to run the duct here:

2--0--0--0
         |
0--0--0--0
|
0--0--3  1

or

2  0--0--0
|  |     |
0  0  0--0
|  |  |
0--0  3  1


Write a program to compute the number of possible ways to run the duct. For the above example, the correct answer is 2.

Input format (read from STDIN):
The input will be a series of integers separated by whitespace.

The first two integers will be W and H, with width and height of the datacenter. These will be followed by W*H more integers, specifying the 2D grid representing the datacenter.

Output format (write to STDOUT):
Your program should write a single integer out: the number of possible ways to run the duct.

See how fast you can make it.

Notes
Our best solution (written in C) can solve the following test case in under 5 seconds on a 2.4GHz Pentium 4, but it's pretty good if you can get to within 1-2 orders of magnitude of that.

7 8
2 0 0 0 0 0 0
0 0 0 0 0 0 0
0 0 0 0 0 0 0
0 0 0 0 0 0 0
0 0 0 0 0 0 0
0 0 0 0 0 0 0
0 0 0 0 0 0 0
3 0 0 0 0 1 1
*/

#include <iostream>
#include <map>
#include <vector>
using namespace std;

/*
struct CalculatedResults
{
	long long previousPath;
	unsigned long numberOfPaths;
};
*/

class DatacenterCooling
{
	typedef map<long long, unsigned long> CalculatedResult;
	typedef vector<CalculatedResult> CalculatedResults;

	CalculatedResults calculatedResults;
	unsigned rows;
	unsigned cols;
	unsigned numberOfElements;
	unsigned **input;
	unsigned stopNode;
	unsigned acceptableResult;

	static const unsigned START = 2;
	static const unsigned STOP = 3;
	static const unsigned OTHERS = 1;
	long long found, stored;

	unsigned getNodeNumberFromLocation(unsigned row, unsigned col)
	{
		return row*this->cols + col;
	}

	void getLocationFromNodeNumber(unsigned nodeNumber, unsigned& row, unsigned& col)
	{
		row = nodeNumber / this->cols;
		col = nodeNumber % this->cols;
	}

	unsigned getStartNode()
	{
		return this->getStartStopNode(START);
	}

	unsigned getStopNode()
	{
		return this->getStartStopNode(STOP);
	}

	unsigned getStartStopNode(unsigned value)
	{
		for (unsigned i = 0; i < this->rows; i++)
		{
			for (unsigned j = 0; j < this->cols; j++)
			{
				if (this->input[i][j] == value)
				{
					return this->getNodeNumberFromLocation(i, j);
				}
			}
		}

		return -1;
	}

	bool isNodeAlreadyCovered(unsigned nodeNumber, long long alreadyCovered)
	{
		long long result = 0x1;
		for(unsigned i = 0; i < nodeNumber; i++)
		{
			result = result << 1;
		}
		return ((result & alreadyCovered) != 0);
	}

	void markNodeCovered(unsigned nodeNumber, long long& alreadyCovered)
	{
		long long result = 0x1;
		for(unsigned i = 0; i < nodeNumber; i++)
		{
			result = result << 1;
		}

		alreadyCovered |= result;
	}

	signed getTopNode(unsigned thisNodeNumber)
	{
		return (thisNodeNumber - this->cols);
	}

	signed getBottomNode(unsigned thisNodeNumber)
	{
		unsigned bottom = thisNodeNumber + this->cols;
		if (bottom < this->numberOfElements)
			return bottom;
		return -1;
	}

	signed getLeftNode(unsigned thisNodeNumber)
	{
		if (thisNodeNumber % this->cols == 0)
			return -1;
		return thisNodeNumber - 1;
	}

	signed getRightNode(unsigned thisNodeNumber)
	{
		if ((thisNodeNumber + 1) % this->cols == 0)
			return -1;
		return thisNodeNumber + 1;
	}

	bool shouldIgnoreNode(unsigned nodeNumber)
	{
		unsigned row, col;
		this->getLocationFromNodeNumber(nodeNumber, row, col);
		return this->shouldIgnoreNode(row, col);
	}

	bool shouldIgnoreNode(unsigned row, unsigned col)
	{
		return (this->input[row][col] == OTHERS);
	}

	unsigned long getTotalPathsFromNodeAndCurrentlyCovered(unsigned thisNodeNumber, long long alreadyCovered)
	{
		long long alreadyCoveredOriginal = alreadyCovered;
		CalculatedResult calculatedResult = this->calculatedResults[thisNodeNumber];
		CalculatedResult::iterator it;
		it = calculatedResult.find(alreadyCoveredOriginal);
		if (it != calculatedResult.end())
		{
			//cout << "Found: Node: " << thisNodeNumber << "; Covered: " << alreadyCovered << "; Value: " << it->second << endl;
			this->found++;
			return it->second;
		}

		if (this->isNodeAlreadyCovered(thisNodeNumber, alreadyCovered) || this->shouldIgnoreNode(thisNodeNumber))
		{
			return 0;
		}

		this->markNodeCovered(thisNodeNumber, alreadyCovered);
		if (thisNodeNumber == this->stopNode)
		{
			if (alreadyCovered == this->acceptableResult)
			{
				// Found another path;
				return 1;
			}

			// Found a path that does not cover all nodes.
			return 0;
		}

		signed topNode = this->getTopNode(thisNodeNumber);
		signed bottomNode = this->getBottomNode(thisNodeNumber);
		signed leftNode = this->getLeftNode(thisNodeNumber);
		signed rightNode = this->getRightNode(thisNodeNumber);
		unsigned long topPaths = 0, bottomPaths = 0, leftPaths = 0, rightPaths = 0;

		if (topNode >= 0)
		{
			long long alreadyCoveredTop = alreadyCovered;
			topPaths = this->getTotalPathsFromNodeAndCurrentlyCovered(topNode, alreadyCoveredTop);
		}
		if (bottomNode >= 0)
		{
			long long alreadyCoveredBottom = alreadyCovered;
			bottomPaths = this->getTotalPathsFromNodeAndCurrentlyCovered(bottomNode, alreadyCoveredBottom);
		}
		if (leftNode >= 0)
		{
			long long alreadyCoveredLeft = alreadyCovered;
			leftPaths = this->getTotalPathsFromNodeAndCurrentlyCovered(leftNode, alreadyCoveredLeft);
		}
		if (rightNode >= 0)
		{
			long long alreadyCoveredRight = alreadyCovered;
			rightPaths = this->getTotalPathsFromNodeAndCurrentlyCovered(rightNode, alreadyCoveredRight);
		}

		unsigned long result = topPaths + bottomPaths + leftPaths + rightPaths;
		calculatedResult[alreadyCoveredOriginal] = result;
		this->calculatedResults[thisNodeNumber] = calculatedResult;
		//cout << "Storing: Node: " << thisNodeNumber << "; Covered: " << alreadyCoveredOriginal << "; Value: " << result << endl;
		this->stored++;
		return result;
	}

public:
	DatacenterCooling()
	{
		cin >> this->cols;
		cin >> this->rows;
		this->numberOfElements = this->rows * this-> cols;

		unsigned k = 0;
		unsigned bit = 0x1; this->acceptableResult = 0;
		this->input = new unsigned* [this->rows];
		for (unsigned i = 0; i < this->rows; i++)
		{
			this->input[i] = new unsigned [this->cols];
			for (unsigned j = 0; j < this->cols; j++, k++)
			{
				cin >> this->input[i][j];
				if (!this->shouldIgnoreNode(i, j))
				{
					this->acceptableResult |= bit;
				}
				bit = bit << 1;

				CalculatedResult calculatedResult;
				this->calculatedResults.push_back(calculatedResult);
			}
		}

		//cout << this->calculatedResults.size() << endl;
		unsigned startNode = this->getStartNode();
		this->stopNode = this->getStopNode();
		//cout << startNode << '\t' << this->stopNode << endl;

		long long alreadyCovered = 0; this->found = 0;
		cout << this->getTotalPathsFromNodeAndCurrentlyCovered(startNode, alreadyCovered) << endl;
	}

	~DatacenterCooling()
	{
		for (unsigned i = 0; i < this->rows; i++)
		{
			delete []this->input[i];
		}
		delete []this->input;

		cout << "Stored: " << this->stored << endl;
		cout << "Found: " << this->found << endl;
	}
};