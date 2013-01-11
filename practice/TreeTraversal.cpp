#include <iostream>
#include <cstdlib>
#include <time.h>
using namespace std;

typedef struct tagNode
{
	int info;
	tagNode *left;
	tagNode *right;
} Node;

class BinaryTree
{
	private:
		Node *root;
		static bool initialized;
		static const int MAX_ELEMENTS = 15;

	public:
		BinaryTree(void) : root(NULL)
		{
			if (!initialized)
			{
				srand(time(NULL));
				initialized = true;
			}
			
			this->Build();
		}
		
		~BinaryTree(void)
		{
			this->Free(this->root);
		}

	private:
		void Build(void)
		{
			int numberOfElements = rand() % MAX_ELEMENTS + 1;
			cout << "Number of elements: " << numberOfElements << endl;
			for (int i = 0; i < numberOfElements; i++)
			{
				int info = rand();
				Node* node = new Node();
				if (node == NULL)
				{
					cout << "Memory allocation failed!" << endl;
					this->Free(this->root);
					return;
				}
				node->info = info;
				node->left = NULL;
				node->right = NULL;

				this->InsertNode(node);
			}

			this->DisplayPreOrder(this->root);
			this->DisplayInOrder(this->root);
			this->DisplayPostOrder(this->root);
		}

		Node* FindPreOrderParent(int info, Node* node)
		{
			if (node == NULL)
			{
				return NULL;
			}
			
			Node *next = NULL;
			if (node->info < info)
			{
				next = this->FindPreOrderParent(info, node->right);
			}
			else if (node->info > info)
			{
				next = this->FindPreOrderParent(info, node->left);
			}

			return (next == NULL) ? node : next;
		}

		void DisplayPreOrder(Node *node)
		{
			if (node == this->root)
			{
				cout << "DisplayPreOrder:" << endl;
			}
			if (node == NULL)
			{
				return;
			}
			cout << node->info << endl;
			this->DisplayPreOrder(node->left);
			this->DisplayPreOrder(node->right);
		}
		
		void DisplayInOrder(Node *node)
		{
			if (node == this->root)
			{
				cout << "DisplayInOrder:" << endl;
			}
			if (node == NULL)
			{
				return;
			}
			this->DisplayInOrder(node->left);
			cout << node->info << endl;
			this->DisplayInOrder(node->right);
		}
		
		void DisplayPostOrder(Node *node)
		{
			if (node == this->root)
			{
				cout << "DisplayPostOrder:" << endl;
			}
			if (node == NULL)
			{
				return;
			}
			this->DisplayPostOrder(node->left);
			this->DisplayPostOrder(node->right);
			cout << node->info << endl;
		}
		
		void InsertNode(Node *parent, Node *node)
		{
			if (node->info == parent->info)
			{
				cout << "Dropping: " << node->info << endl;
				return;
			}

			if (node->info < parent->info)
			{
				if (parent->left == NULL)
				{
					parent->left = node;
					cout << "Added: " << node->info << " to the left of: " << parent->info <<endl;
				}
				else
				{
				this->InsertNode(parent->left, node);
				}
			}
			else
			{
				if (parent->right == NULL)
				{
					parent->right = node;
					cout << "Added: " << node->info << " to the right of: " << parent->info <<endl;
				}
				else
				{
				this->InsertNode(parent->right, node);
				}
			}
		}
		
		void InsertNode(Node *node)
		{
			if (this->root == NULL)
			{
				this->root = node;
				cout << "Added as root: " << node->info << endl;
				return;
			}
			this->InsertNode(this->root, node);
		}
		
		void Free(Node *node)
		{
			if (node != NULL)
			{
				this->Free(node->left);
				cout << "Deleting: " << node->info << endl;
				this->Free(node->right);
			}
		}
};
bool BinaryTree::initialized;
const int BinaryTree::MAX_ELEMENTS;

int main (int argc, char* argv[])
{
	BinaryTree *tree = new BinaryTree();
	delete tree; tree = NULL;
	return 0;
}
