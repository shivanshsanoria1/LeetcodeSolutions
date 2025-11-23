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
private:
    void dfs(TreeNode* curr, int val, int depth){
        if(curr == nullptr)
            return;

        if(depth == 0)
        {
            TreeNode* temp = nullptr;
            
            // create a new left node
            TreeNode* newLeftNode = new TreeNode(val); 
            // save the curr's left-child in temp
            temp = curr->left; 
            // make the new node the left-child of curr
            curr->left = newLeftNode; 
            // make the old left-child the left-child of new node
            newLeftNode->left = temp; 

            // create a new right node
            TreeNode* newRightNode = new TreeNode(val); 
            // save the curr's right-child in temp
            temp = curr->right; 
            // make the new node the right-child of curr
            curr->right = newRightNode; 
            // make the old right-child the right-child of new node
            newRightNode->right = temp; 
            
            return;
        }

        dfs(curr->left, val, depth - 1);
        dfs(curr->right, val, depth - 1);
    }

public:    
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth == 1)
        {
            // create a new node
            TreeNode* newNode = new TreeNode(val);
            // make root the left child of new node
            newNode->left = root;
            
            return newNode;
        }

        dfs(root, val, depth - 2);

        return root;
    }
};