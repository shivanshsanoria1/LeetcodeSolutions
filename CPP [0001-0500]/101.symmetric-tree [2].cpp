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
    bool isSymmetric(TreeNode* root) { // ITERATIVE
        if(root==NULL)
            return true;
        queue<TreeNode*> qu;
        qu.push(root->left);
        qu.push(root->right);
        while(!qu.empty()) // while queue is not empty
        {
            TreeNode* curr1=qu.front();
            qu.pop();
            TreeNode* curr2=qu.front();
            qu.pop();
            if(curr1==NULL && curr2==NULL) // both are NULL
                continue;
            if(curr1==NULL || curr2==NULL) // one is NULL and the other is not NULL
                return false;
            if(curr1->val != curr2->val) // both are not NULL but have unequal value
                return false;
            qu.push(curr1->left); // push left child of curr1
            qu.push(curr2->right); // push right child of curr2
            qu.push(curr1->right); // push right child of curr1
            qu.push(curr2->left); // push left child of curr2
        }
        return true; // if queue becomes empty
    }
};