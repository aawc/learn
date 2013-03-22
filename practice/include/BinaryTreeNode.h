class BinaryTreeNode
{
	protected:
		int info;
		BinaryTreeNode* left;
		BinaryTreeNode* right;

	public:
		BinaryTreeNode();
		virtual ~BinaryTreeNode();
		BinaryTreeNode(const BinaryTreeNode& b);
		BinaryTreeNode& operator=(const BinaryTreeNode& b);

		int getInfo();
		BinaryTreeNode* getLeft();
		BinaryTreeNode* getRight();
		void setInfo(int);
		void setLeft(BinaryTreeNode*);
		void setRight(BinaryTreeNode*);
};
