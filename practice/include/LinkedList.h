#include "LinkedListNode.h"

class LinkedList
{
	private:
		static bool initialized;
		LinkedListNode *root, *last;
		bool isCircular;
		void construct (const unsigned maxElements, bool isCircular);

	public:
		LinkedList (const unsigned maxElements);
		LinkedList (const unsigned maxElements, bool isCircular);
		~LinkedList (void);
		void Display (void);
		bool LoopExpectationMatches (void);
		LinkedListNode* FindFromBack(unsigned numberOfElementToFindFromBack);

	private:
		void Free (void);
		bool HasLoop (void);
};