class BinaryTreeNode;

class BinaryTree
{
	protected:
		BinaryTreeNode* root;
		static bool initialized;
		static const int MAX_ELEMENTS = 15;

	public:
		BinaryTree(void);
		BinaryTree(const BinaryTree& b);
		BinaryTree& operator=(const BinaryTree& b);

		virtual ~BinaryTree(void);

	protected:
	    static void Init(void);
		void Build(void);
		BinaryTreeNode* FindPreOrderParent(int info, BinaryTreeNode* node);
		void DisplayPreOrder(BinaryTreeNode* node);
		void DisplayInOrder(BinaryTreeNode* node);
		void DisplayPostOrder(BinaryTreeNode* node);
		void InsertNode(BinaryTreeNode* parent, BinaryTreeNode* node);
		void InsertNode(BinaryTreeNode* node);
		void Free(BinaryTreeNode* node);
};
