#include <cstdlib>
//#include "../include/BinaryTree.h"
//#include "../include/ThreadedBinaryTree.h"
//#include "../include/MergeSort.h"
//#include "../include/MergeSortSTL.h"
//#include "../include/InsertSort.h"
//#include "../include/InsertSortSTL.h"
#include "../include/QuickSortSTL.h"
using namespace std;

int randomNumberGenerator()
{
	return rand();
}

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

	const unsigned MAX_ELEMENTS = 10;
	QuickSortSTL<int> *quickSortSTL = new QuickSortSTL<int>(MAX_ELEMENTS, randomNumberGenerator);
	delete quickSortSTL; quickSortSTL = NULL;

	return 0;
}