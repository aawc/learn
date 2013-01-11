#include <iostream>
#include <cstdlib>
#include <vector>
#include <time.h>
using namespace std;

typedef struct tagNode
{
	int info;
	tagNode *next;
} Node;

class LinkedList
{
	private:
		static bool initialized;
		Node *root, *last;
		bool isCircular;

	public:
		LinkedList (void)
			: isCircular(false), root(NULL), last(NULL)
		{
			if (!initialized)
			{
				srand(time(NULL));
				initialized = true;
			}

			int numberOfElements = rand() % 15 + 1;
			cout << "Number of elements: " << numberOfElements << endl;
			for (int i = 0; i < numberOfElements; i++)
			{
				int info = rand();
				Node* node = new Node();
				if (node == NULL)
				{
					cout << "Memory allocation failed!" << endl;
					this->Free();
					return;
				}
				node->info = info;
				node->next = NULL;

				if (this->last == NULL)
				{
					this->root = this->last = node;
				}
				else
				{
					this->last->next = node;
				}

				this->last = node;

				cout << "Added: " << info << endl;
			}
			
			this->isCircular = (rand() % 2 == 1);
			if (this->isCircular)
			{
				this->last->next = this->root;
				cout << endl << "The list is circular!" << endl;
			}

			this->Display();
		}

		~LinkedList (void)
		{
			this->Free();
		}

		void Display (void)
		{
			Node* ptr = this->root;
			cout << endl << "The list is:" << endl;
			bool rootShown = false;
			while (ptr != NULL && ptr != this->root || !rootShown)
			{
				rootShown = true;
				cout << ptr->info << endl;
				ptr = ptr->next;
			}
			cout << endl;
		}
		
		bool LoopExpectationMatches (void)
		{
			bool loopDetected = this->HasLoop();
			if (loopDetected)
			{
				cout << "Loop detected!" << endl;
			}
			
			return this->isCircular == loopDetected;
		}

	private:
		void Free (void)
		{
			if (this->last == NULL)
			{
				return;
			}
			this->last->next = NULL;

			cout << endl << "Clearing list:" << endl;
			Node* ptr = this->root;
			while (ptr != NULL)
			{
				this->root = ptr->next;

				cout << "Deleting: " << ptr->info << endl;
				delete ptr;
				ptr = this->root;
			}
		}

		bool HasLoop (void)
		{
			if (this->root == NULL)
			{
				return false;
			}

			Node *ptr1 = this->root, *ptr2 = this->root->next;
			while (ptr1 != NULL && ptr2 != NULL && ptr2->next != NULL)
			{
				if (ptr1 == ptr2)
				{
					return true;
				}

				ptr1 = ptr1->next;
				ptr2 = ptr2->next->next;
			}
			return false;
		}
};
bool LinkedList::initialized;

class LinkedListLoop
{
	private:
		LinkedList *list;

	public:
		LinkedListLoop(void)
		{
			this->list = new LinkedList();
			if (!this->list->LoopExpectationMatches())
			{
				cout << "We got a problem!" << endl;
			}
			else
			{
				cout << "All's well!" << endl;
			}
		}

		~LinkedListLoop(void)
		{
			delete this->list;
			this->list = NULL;
		}
};

int main (int argc, char* argv[])
{
	LinkedListLoop *loop = new LinkedListLoop();
	delete loop; loop = NULL;
}
