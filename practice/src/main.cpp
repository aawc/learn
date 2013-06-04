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
#include "../include/FullJoin.h"
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
	LinkedListLoop *linkedListLoop = new LinkedListLoop();
	delete linkedListLoop; linkedListLoop = NULL;
	*/

	vector<Field1> fields1;// {0, "ZERO"}, {1, "ONE"}, {2, "TWO"}, {2, "two"}, {3, "THREE"}
	vector<Field2> fields2;// {1, "ek"}, {2, "do"}, {2, "du"}, {3, "tray"}, {4, "char"}
	fields1.push_back(Field1(0, "ZERO"));
	fields1.push_back(Field1(1, "ONE"));
	fields1.push_back(Field1(2, "TWO"));
	fields1.push_back(Field1(2, "two"));
	fields1.push_back(Field1(3, "THREE"));
	fields1.push_back(Field1(3, "three"));
	fields1.push_back(Field1(4, "FOUR"));
	fields1.push_back(Field1(5, "FIVE"));
	fields1.push_back(Field1(5, "five"));

	fields2.push_back(Field2(1, "ek"));
	fields2.push_back(Field2(2, "do"));
	fields2.push_back(Field2(2, "du"));
	fields2.push_back(Field2(3, "tray"));
	fields2.push_back(Field2(4, "char"));
	fields2.push_back(Field2(4, "chaar"));

	fullJoin(fields1, fields2);

	return 0;
}