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
    void inorder(TreeNode *root, vector<int>& vec)
    {
        if(root==NULL)
            return;
        inorder(root->left,vec);
        vec.push_back(root->val);
        inorder(root->right,vec);
    }
    
    bool findTarget(TreeNode* root, int k) { //T.C.=O(n) , S.C.=O(n)
        vector<int> vec;
        inorder(root,vec); // inorder traversal of a BST gives ascending order
        int left=0, right=vec.size()-1;
        while(left < right)
        {
            if(vec[left]+vec[right] == k)
                return true;
            if(vec[left]+vec[right] < k)
                left++;
            else
                right--;
        }
        return false;
    }
};