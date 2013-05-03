#include "LinkedListNode.h"

class LinkedList
{
	private:
		static bool initialized;
		LinkedListNode *root, *last;
		bool isCircular;

	public:
		LinkedList (void);
		~LinkedList (void);
		void Display (void);
		bool LoopExpectationMatches (void);

	private:
		void Free (void);
		bool HasLoop (void);
};