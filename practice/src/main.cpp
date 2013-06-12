#include <cstdlib>
#include <vector>
//#include "../include/BinaryTree.h"
//#include "../src/BinaryTree.cpp"
//#include "../include/ThreadedBinaryTree.h"
//#include "../include/MergeSort.h"
//#include "../include/MergeSortSTL.h"
//#include "../include/InsertSort.h"
//#include "../include/InsertSortSTL.h"
//#include "../include/QuickSortSTL.h"
//#include "../include/LinkedListLoop.h"
//#include "../include/FullJoin.h"
#include "../include/LinkedListNFromBack.h"
using namespace std;

int randomNumberGenerator()
{
	return rand();
}

int main (int, char**)
{
	/*
	const unsigned MAX_ELEMENTS = 15;
	BinaryTree<unsigned> *binaryTree = new BinaryTree<unsigned>(MAX_ELEMENTS);
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

	/*
	const unsigned MAX_ELEMENTS = 10;
	MergeSortSTL* mergeSortSTL = new MergeSortSTL(MAX_ELEMENTS);
	delete mergeSortSTL; mergeSortSTL = NULL;
	*/

	/*
	const unsigned MAX_ELEMENTS = 10;
	InsertSort* insertSort = new InsertSort(MAX_ELEMENTS);
	delete insertSort; insertSort = NULL;
	*/

	/*
	const unsigned MAX_ELEMENTS = 10;
	InsertSortSTL* insertSortSTL = new InsertSortSTL(MAX_ELEMENTS);
	delete insertSortSTL; insertSortSTL = NULL;
	*/

	/*
	const unsigned MAX_ELEMENTS = 10;
	QuickSortSTL<int> *quickSortSTL = new QuickSortSTL<int>(MAX_ELEMENTS, randomNumberGenerator);
	delete quickSortSTL; quickSortSTL = NULL;
	*/

	/*
	const unsigned MAX_ELEMENTS = 15;
	LinkedListLoop *linkedListLoop = new LinkedListLoop(MAX_ELEMENTS);
	delete linkedListLoop; linkedListLoop = NULL;
	*/

	/*
	FullJoin* fullJoin = new FullJoin;
	delete fullJoin; fullJoin = NULL;
	*/

	const unsigned MAX_ELEMENTS = 15;
	LinkedListNFromBack * linkedListNFromBack = new LinkedListNFromBack(MAX_ELEMENTS);
	delete linkedListNFromBack; linkedListNFromBack = NULL;

	return 0;
}