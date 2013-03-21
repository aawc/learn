#include <cstdlib>
#include "../include/ThreadedBinaryTree.h"

using namespace std;

int main (int, char**)
{
	BinaryTree *tree = new BinaryTree();
	delete tree; tree = NULL;
	return 0;
}
