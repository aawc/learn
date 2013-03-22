#include <cstdlib>
#include "../include/ThreadedBinaryTree.h"

using namespace std;

int main (int, char**)
{
	ThreadedBinaryTree *threadedBinaryTree = new ThreadedBinaryTree();
	delete threadedBinaryTree; threadedBinaryTree = NULL;
	return 0;
}
