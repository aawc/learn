class ThreadedBinaryTreeNode;

class ThreadedBinaryTree
{
	private:
		ThreadedBinaryTreeNode* root;
		static bool initialized;
		static const int MAX_ELEMENTS = 20;

	private:
	    static void Init(void);
		void Build(void);
		ThreadedBinaryTreeNode* FindPreOrderParent(int info, ThreadedBinaryTreeNode* node);
		void Display();
		void DisplayPreOrder(ThreadedBinaryTreeNode* node);
		void DisplayInOrder(ThreadedBinaryTreeNode* node);
		void DisplayPostOrder(ThreadedBinaryTreeNode* node);
		void InsertNode(ThreadedBinaryTreeNode* parent, ThreadedBinaryTreeNode* node);
		void InsertNode(ThreadedBinaryTreeNode* node);
		void Free(ThreadedBinaryTreeNode* node);

	public:
		ThreadedBinaryTree(void);
		ThreadedBinaryTree(const ThreadedBinaryTree& b);
		ThreadedBinaryTree& operator=(const ThreadedBinaryTree& b);

		virtual ~ThreadedBinaryTree(void);

		void BuildThreads(void);

	private:
		static void BuildThreadsForNode(ThreadedBinaryTreeNode* node, ThreadedBinaryTreeNode* subTreePredecessor, ThreadedBinaryTreeNode* subTreeSuccessor, ThreadedBinaryTreeNode** first, ThreadedBinaryTreeNode** last);
};
