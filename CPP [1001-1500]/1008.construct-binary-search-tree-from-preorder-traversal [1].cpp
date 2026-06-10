/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode *solve(vector<int>& pre, int start, int end)
    {
        if(start > end)
            return NULL;
        TreeNode *root = new TreeNode(pre[start]);
        int rightStart = start + 1;
        while(rightStart <= end)
        {
            if(pre[rightStart] > pre[start])
                break;
            rightStart++;
        }
        root->left = solve(pre, start+1, rightStart-1);
        root->right = solve(pre, rightStart, end);
        return root;
    }

    TreeNode* bstFromPreorder(vector<int>& preorder) {
        return solve(preorder, 0, preorder.size()-1);
    }
};