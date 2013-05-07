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

#include <ctime>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

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
	unsigned *solution;

	// This variable represents the bitmap of an acceptable result
	// i.e. All the nodes that need to covered are marked with 1, all other are marked with 0.
	// It helps us determine whether we have covered all valid nodes in traversing a path.
	unsigned long long acceptableResult;
	unsigned numberOfValidNodes;

	static const unsigned START = 2;
	static const unsigned STOP = 3;
	static const unsigned OTHERS = 1;
	unsigned long long found, stored;

	inline unsigned getNodeNumberFromLocation(unsigned row, unsigned col)
	{
		return row*this->cols + col;
	}

	inline void getLocationFromNodeNumber(unsigned nodeNumber, unsigned& row, unsigned& col)
	{
		row = nodeNumber / this->cols;
		col = nodeNumber % this->cols;
	}

	inline unsigned getStartNode()
	{
		return this->getStartStopNode(START);
	}

	inline unsigned getStopNode()
	{
		return this->getStartStopNode(STOP);
	}

	inline unsigned getStartStopNode(unsigned value)
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

	inline bool isNodeAlreadyCovered(unsigned nodeNumber, unsigned long long alreadyCovered)
	{
		long long result = 0x1;
		for(unsigned i = 0; i < nodeNumber; i++)
		{
			result = result << 1;
		}
		return ((result & alreadyCovered) != 0);
	}

	inline void markNodeCovered(unsigned nodeNumber, unsigned index, unsigned long long& alreadyCovered)
	{
		unsigned long long result = 0x1;
		for(unsigned i = 0; i < nodeNumber; i++)
		{
			result = result << 1;
		}

		alreadyCovered |= result;
		this->solution[index] = nodeNumber;
	}

	inline signed getTopNode(unsigned thisNodeNumber)
	{
		return (thisNodeNumber - this->cols);
	}

	inline signed getBottomNode(unsigned thisNodeNumber)
	{
		unsigned bottom = thisNodeNumber + this->cols;
		if (bottom < this->numberOfElements)
			return bottom;
		return -1;
	}

	inline signed getLeftNode(unsigned thisNodeNumber)
	{
		if (thisNodeNumber % this->cols == 0)
			return -1;
		return thisNodeNumber - 1;
	}

	inline signed getRightNode(unsigned thisNodeNumber)
	{
		if ((thisNodeNumber + 1) % this->cols == 0)
			return -1;
		return thisNodeNumber + 1;
	}

	inline bool shouldIgnoreNode(unsigned nodeNumber)
	{
		unsigned row, col;
		this->getLocationFromNodeNumber(nodeNumber, row, col);
		return this->shouldIgnoreNode(row, col);
	}

	inline bool shouldIgnoreNode(unsigned row, unsigned col)
	{
		return (this->input[row][col] == OTHERS);
	}

	unsigned long getTotalPathsFromNodeAndCurrentlyCovered(unsigned thisNodeNumber, unsigned thisIndex, unsigned long long alreadyCovered)
	{
		if (this->shouldIgnoreNode(thisNodeNumber) || this->isNodeAlreadyCovered(thisNodeNumber, alreadyCovered))
		{
			// We're coming back to a node we've already traversed in the current path, OR
			// This is an "OTHERS" node, so we can't use this node.
			return 0;
		}

		this->markNodeCovered(thisNodeNumber, thisIndex, alreadyCovered);
		if (thisNodeNumber == this->stopNode)
		{
			if (alreadyCovered == this->acceptableResult)
			{
				// Found another path;
/*
				cout << "Solution: ";
				for (unsigned i = 0; i <= thisIndex; i++)
				{
					cout << this->solution[i] << "-";
				}
				cout << endl;
*/

				return 1;
			}

			// Found a path that does not cover all nodes.
			return 0;
		}

		double ratio;

		CalculatedResult calculatedResult = this->calculatedResults[thisNodeNumber];
		CalculatedResult::iterator it;
		it = calculatedResult.find(alreadyCovered);
		if (it != calculatedResult.end())
		{
			//cout << "Found: Node: " << thisNodeNumber << "; Covered: " << alreadyCovered << "; Value: " << it->second << endl;
			this->found += (this->numberOfValidNodes - thisIndex);
			ratio = double(this->found)/this->stored;
			cout << "Stored: " << this->stored << "; Found: " << this->found << "; Ratio: " << ratio << endl;
			if (it->second != 0)
				cout << "Second: " << it->second << endl;
			return it->second;
		}

		signed topNode = this->getTopNode(thisNodeNumber);
		signed bottomNode = this->getBottomNode(thisNodeNumber);
		signed leftNode = this->getLeftNode(thisNodeNumber);
		signed rightNode = this->getRightNode(thisNodeNumber);
		unsigned long topPaths = 0, bottomPaths = 0, leftPaths = 0, rightPaths = 0;

		if (topNode >= 0)
		{
			unsigned long long alreadyCoveredTop = alreadyCovered;
			topPaths = this->getTotalPathsFromNodeAndCurrentlyCovered(topNode, thisIndex + 1, alreadyCoveredTop);
		}
		if (bottomNode >= 0)
		{
			unsigned long long alreadyCoveredBottom = alreadyCovered;
			bottomPaths = this->getTotalPathsFromNodeAndCurrentlyCovered(bottomNode, thisIndex + 1, alreadyCoveredBottom);
		}
		if (leftNode >= 0)
		{
			unsigned long long alreadyCoveredLeft = alreadyCovered;
			leftPaths = this->getTotalPathsFromNodeAndCurrentlyCovered(leftNode, thisIndex + 1, alreadyCoveredLeft);
		}
		if (rightNode >= 0)
		{
			unsigned long long alreadyCoveredRight = alreadyCovered;
			rightPaths = this->getTotalPathsFromNodeAndCurrentlyCovered(rightNode, thisIndex + 1, alreadyCoveredRight);
		}

		unsigned long result = topPaths + bottomPaths + leftPaths + rightPaths;
		calculatedResult[alreadyCovered] = result;
		this->calculatedResults[thisNodeNumber] = calculatedResult;
		//cout << "Storing: Node: " << thisNodeNumber << "; Covered: " << alreadyCoveredOriginal << "; Value: " << result << endl;
		this->stored++;
		ratio = double(this->found)/this->stored;
		cout << "Stored: " << this->stored << "; Found: " << this->found << "; Ratio: " << ratio << endl;
		return result;
	}

public:
	DatacenterCooling()
	{
		cin >> this->cols;
		cin >> this->rows;
		this->numberOfElements = this->rows * this-> cols;

		this->numberOfValidNodes = 0;
		unsigned long long bit = 0x1; this->acceptableResult = 0;
		this->input = new unsigned* [this->rows];
		for (unsigned i = 0; i < this->rows; i++)
		{
			this->input[i] = new unsigned [this->cols];
			for (unsigned j = 0; j < this->cols; j++)
			{
				cin >> this->input[i][j];
				if (!this->shouldIgnoreNode(i, j))
				{
					this->acceptableResult |= bit;
					this->numberOfValidNodes++;
				}
				bit = bit << 1;

				CalculatedResult calculatedResult;
				this->calculatedResults.push_back(calculatedResult);
			}
		}
		this->solution = new unsigned [this->numberOfValidNodes];

		//cout << this->calculatedResults.size() << endl;
		unsigned startNode = this->getStartNode();
		this->stopNode = this->getStopNode();
		//cout << startNode << '\t' << this->stopNode << endl;

		unsigned long long alreadyCovered = 0;
		this->found = this->stored = 0;
		//const clock_t startTime = clock();
		cout << this->getTotalPathsFromNodeAndCurrentlyCovered(startNode, 0, alreadyCovered) << endl;
		//const clock_t endTime = clock();

		//cout << "Total time (in ms): " << (endTime - startTime) << endl;
	}

	~DatacenterCooling()
	{
		for (unsigned i = 0; i < this->rows; i++)
		{
			delete []this->input[i];
		}
		delete []this->input;
		delete []this->solution;

		//cout << "Stored: " << this->stored << endl;
		//cout << "Found: " << this->found << endl;
	}
};

/*
int main(int argc, char **argv)
{
	DatacenterCooling* datacenterCooling = new DatacenterCooling;
	delete datacenterCooling; datacenterCooling = NULL;
	return 0;
}
*/