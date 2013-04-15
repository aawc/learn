#include <cstdlib>
//#include "../include/BinaryTree.h"
#include "../include/ThreadedBinaryTree.h"

using namespace std;

int main (int, char**)
{
	/*
	BinaryTree *binaryTree = new BinaryTree();
	delete binaryTree; binaryTree = NULL;
	*/
	ThreadedBinaryTree *threadedBinaryTree = new ThreadedBinaryTree();
	delete threadedBinaryTree; threadedBinaryTree = NULL;
	return 0;
}
