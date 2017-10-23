#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
class Solution
{
	public:
		TreeNode* buildTree(vector<int> &preorder, vector<int> &inorder)
		{
			if(preorder.empty())	return NULL;
			TreeNode *root = new TreeNode(preorder[0]);
			
			auto inorder_begin = inorder.begin();
			auto preorder_begin = preorder.begin();
			auto root_pos = find(inorder_begin, inorder.end(), preorder[0]);
			int left_size = distance(inorder_begin, root_pos);
			
			
			vector<int> left_preorder(next(preorder_begin), next(preorder_begin, left_size + 1));
			vector<int> left_inorder(inorder_begin, next(inorder_begin, left_size));
			
			vector<int> right_preorder(next(preorder_begin, left_size + 1), preorder.end());
			vector<int> right_inorder(next(root_pos), inorder.end());
			root->left = buildTree(left_preorder, left_inorder);
			root->right = buildTree(right_preorder, right_inorder);
			return root;
		}
};
int main()
{
	vector<int> a(1, -1);
	vector<int> b(1, -1);
	Solution s;
	s.buildTree(a, b);
	return 0;
}

