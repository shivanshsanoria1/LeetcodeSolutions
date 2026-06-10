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
    int i;
    
    void inorder1(vector<int>& vec, TreeNode* curr)
    {
        if(curr==NULL)
            return;
        inorder1(vec,curr->left);
        vec.push_back(curr->val);
        inorder1(vec,curr->right);
    }
    
    void inorder2(vector<int>& vec, TreeNode* curr)
    {
        if(curr==NULL)
            return;
        inorder2(vec,curr->left);
        curr->val=vec[i];
        i++;
        inorder2(vec,curr->right);
    }
    
    void recoverTree(TreeNode* root) { //T.C.=O(nlogn) , S.C.=O(n)
        vector<int> vec;
        inorder1(vec,root);
        sort(vec.begin(),vec.end());
        i=0;
        inorder2(vec,root);
    }
};
//inorder traversal of BST gives values in sorted form