#include<iostream>
#include<vector>
#include<stack>
using namespace std;

/*
 Definition for a binary tree node.
 */
 struct TreeNode {
	 int val;
	 TreeNode *left;
	 TreeNode *right;
	 TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
		vector<int> result;
		if(nullptr == root)
		{
				return result;
		}
			
		stack<TreeNode*> tree_stack;
		TreeNode* cur = nullptr;
		TreeNode* pre = nullptr;
		tree_stack.push(root);

		while(!tree_stack.empty())
		{
				cur = tree_stack.top();
				if((nullptr == cur->left && nullptr == cur->right) ||
					(nullptr != pre && (pre == cur->left || pre == cur->right)))
				{
						tree_stack.pop();
						result.push_back(cur->val);
						pre = cur;
				}
				else
				{
						if(nullptr != cur->right)
						{
								tree_stack.push(cur->right);
						}

						if(nullptr != cur->left)
						{
								tree_stack.push(cur->left);
						}
				}
		}

		return result;
    }
};


int main(void)
{
		TreeNode t1 = {1};
		TreeNode t2 = {2};
		TreeNode t3 = {3};
		TreeNode t4 = {4};
		TreeNode t5 = {5};

		t1.left = &t2;
		t1.right = &t3;
		t2.left = &t4;
		t2.right = &t5;
		Solution solution;
		vector<int> result = solution.postorderTraversal(&t1);
		for(auto& data : result)
		{
				cout << data << " " << endl;
		}
		return 0;
}
