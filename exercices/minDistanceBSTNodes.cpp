struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
	int minVal;
	void minDiffInBSTR(TreeNode* p) {
		if (p != nullptr) {
			minDiffInBSTR(p->left);
			int prev = p->val;
			minDiffInBSTR(p->right);
		}
	}
public:
    int minDiffInBST(TreeNode* root) {
		return 0;
	}
};

int main() {
	TreeNode* root = new TreeNode(4);
	root->right = new TreeNode(6);
	root->left = new TreeNode(2);
	Solution s;
	s.minDiffInBST(root);
	return 0;
}
