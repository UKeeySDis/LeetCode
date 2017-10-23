class Solution
{
	public:
		TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder)
		{
			if(inorder.empty())	return NULL;
			int val = *prev(postorder.end());
			TreeNode *root = new TreeNode(val);

			auto inorder_begin = inorder.begin();
			auto root_pos = find(inorder_begin, inorder.end(), val);
			auto left_size = distance(inorder_begin, root_pos);

			vector<int> left_inorder(inorder_begin, root_pos);
			vector<int> left_postorder(postorder.begin(), next(postorder.begin(), left_size));

			vector<int> right_inorder(next(root_pos), inorder.end());
			vector<int> right_postorder(next(postorder.begin(), left_size), prev(postorder.end()));
    
            
            root->left = buildTree(left_inorder, left_postorder);
            root->right = buildTree(right_inorder, right_postorder);
            
			return root;
		}
};

