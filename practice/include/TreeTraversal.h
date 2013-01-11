typedef struct tagTreeNode
{
	int info;
	tagTreeNode *left;
	tagTreeNode *right;
} TreeNode;

class BinaryTree
{
	private:
		TreeNode* root;
		static bool initialized;
		static const int MAX_ELEMENTS = 15;

	public:
		BinaryTree(void);
		BinaryTree(const BinaryTree& b);
		BinaryTree& operator=(const BinaryTree& b);

		~BinaryTree(void);

	private:
	    static void Init(void);
		void Build(void);
		TreeNode* FindPreOrderParent(int info, TreeNode* node);
		void DisplayPreOrder(TreeNode* node);
		void DisplayInOrder(TreeNode* node);
		void DisplayPostOrder(TreeNode* node);
		void InsertNode(TreeNode* parent, TreeNode* node);
		void InsertNode(TreeNode* node);
		void Free(TreeNode* node);
};
