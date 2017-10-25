class Solution
{
	public:
		TreeNode* sortedArrayToBST(vector<int>& num)
		{
			return sortedArrayToBST(num.begin(), num.end());
		}
		TreeNode* sortedArrayToBST(vector<int>::iterator first, vector<int>::iterator last)
		{
			const int length = distance(first, last);
			if(length <= 0)	return NULL;

			vector<int>::iterator mid = first + length / 2;
			TreeNode* root = new TreeNode(*mid);
			root->left = sortedArrayToBST(first, mid);
			root->right = sortedArrayToBST(mid + 1, last);
			return root;
		}
};
