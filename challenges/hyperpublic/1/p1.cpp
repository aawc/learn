/* http://hyperpublic.com/challenge/question1 */
using namespace std;

#include <iostream>
#include <vector>
#include <climits>
#include <cstdio>
#include <cstring>

#define DEBUG_CODE 0
#define ERROR_CODE 0

class Node {
	Node* parent;
	std::vector<Node*> children;

public:
	Node (void) : parent(NULL), children(NULL) {
#if DEBUG_CODE
		static int count = 0;
		printf ("%s:%d: Node[%d] for %p\n", __FILE__, __LINE__, ++count, this);
#endif //DEBUG_CODE
	}

	~Node (void) {
#if DEBUG_CODE
		static int count = 0;
		printf ("%s:%d: ~Node[%d] for %p\n", __FILE__, __LINE__, ++count, this);
#endif //DEBUG_CODE
		children.clear();
	}

	void addAsChild (Node* child) {
		children.push_back (child);
		child->setAsParent (this);
#if DEBUG_CODE
		printf ("%s:%d: (%p).addAsChild (%p): influence: %u\n", __FILE__, __LINE__, this, child, getNodesInTreeWithRootAt(this));
#endif //DEBUG_CODE
	}

	void setAsParent (Node *p) {
#if DEBUG_CODE
		printf ("%s:%d: (%p).setAsParent (%p)\n", __FILE__, __LINE__, this, p);
#endif //DEBUG_CODE
		parent = p;
	}

	void displayInfluence (void) {
#if DEBUG_CODE
		printf ("%s:%d: (%p).displayInfluence: %u\n", __FILE__, __LINE__, this, getNodesInTreeWithRootAt(this));
#else
		printf ("%u\n", getNodesInTreeWithRootAt(this));
#endif
	}

	static unsigned getNodesInTreeWithRootAt (Node *root) {
		unsigned numberOfNodes = root->children.size();
#if DEBUG_CODE
		printf ("%s:%d: getNodesInTreeWithRootAt (%p): %u\n", __FILE__, __LINE__, root, numberOfNodes);
#endif //DEBUG_CODE

		// start from the beginning of the array
		std::vector<Node*>::iterator itPos = root->children.begin();
		// iterate over all elements from the vector
		for (; itPos < root->children.end(); itPos++) {
			numberOfNodes += getNodesInTreeWithRootAt(*itPos);
#if DEBUG_CODE
			printf ("%s:%d: getNodesInTreeWithRootAt (%p): %u\n", __FILE__, __LINE__, root, numberOfNodes);
#endif //DEBUG_CODE
		}

		return numberOfNodes;
	}
};

int main (void)
{
	int i = 0, n = 0;
	char line [PATH_MAX];

	cin >> n;
	n = 100;
	if ( (n < 1) || (n >= PATH_MAX) ) {
#if ERROR_CODE
		printf ("%s:%d: n(%d)\n", __FILE__, __LINE__, n);
#endif //ERROR_CODE
		return -1;
	}

	std::vector<Node> nodeList(n);
	while (i < n) {
		cin >> line;
#if DEBUG_CODE
		printf ("%s:%d: i: %d, n: %d | line: %s\n", __FILE__, __LINE__, i, n, line);
#endif //DEBUG_CODE

		int len = strlen(line);
		if (len != n) {
#if ERROR_CODE
			printf ("%s:%d: line: %s | len: %d | n: %d\n", __FILE__, __LINE__, line, len, n);
#endif //ERROR_CODE
			return -1;
		}

		for (int j = 0; j < len; j++) {
			if ( ('x' == line[j]) || ('X' == line[j]) ) {
				if (i == j) {
#if ERROR_CODE
					printf ("%s:%d: i(%d) == j(%d)\n", __FILE__, __LINE__, i, j);
#endif //ERROR_CODE
					return -1;
				}
#if DEBUG_CODE
				printf ("%s:%d: (%d).addAsChild(%d)\n", __FILE__, __LINE__, i, j);
#endif //DEBUG_CODE
				nodeList[i].addAsChild(&nodeList[j]);
			}
		}
		++i;
	}
	for (i = 0; i < n; i++) {
		nodeList[i].displayInfluence ();
	}

	return 0;
}
