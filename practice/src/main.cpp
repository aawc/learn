#include <cstdlib>
//#include "../include/BinaryTree.h"
//#include "../include/ThreadedBinaryTree.h"
//#include "../include/MergeSort.h"
#include "../include/MergeSortSTL.h"

using namespace std;

int main (int, char**)
{
	/*
	BinaryTree *binaryTree = new BinaryTree();
	delete binaryTree; binaryTree = NULL;
	*/
	/*
	ThreadedBinaryTree *threadedBinaryTree = new ThreadedBinaryTree();
	delete threadedBinaryTree; threadedBinaryTree = NULL;
	*/

	/*
	const unsigned MAX_ELEMENTS = 10;
	MergeSort* mergeSort = new MergeSort(MAX_ELEMENTS);
	delete mergeSort; mergeSort = NULL;
	*/

	const unsigned MAX_ELEMENTS = 10;
	MergeSortSTL* mergeSortSTL = new MergeSortSTL(MAX_ELEMENTS);
	delete mergeSortSTL; mergeSortSTL = NULL;

	return 0;
}
