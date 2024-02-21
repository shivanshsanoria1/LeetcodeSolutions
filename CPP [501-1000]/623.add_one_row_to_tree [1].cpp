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
    void preorder(TreeNode* curr, int val, int depth, int curr_depth) //DFS
    {
        if(curr==NULL)
            return;
        if(curr_depth == depth-1)
        {
            TreeNode* temp;
            
            TreeNode* new_left_node = new TreeNode(val); //create new left node
            temp = curr->left; //temp points to the curr left child
            curr->left = new_left_node; //make new node the left child of curr
            new_left_node->left = temp; //make old left child the left child of new node

            TreeNode* new_right_node = new TreeNode(val); //create new right node
            temp = curr->right; //temp points to the curr right child
            curr->right = new_right_node; //make new node the right child of curr
            new_right_node->right = temp; //make old right child the right child of new node
            
            return;
        }
        preorder(curr->left,val,depth,curr_depth+1);
        preorder(curr->right,val,depth,curr_depth+1);
    }
    
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth==1)
        {
            TreeNode* newNode = new TreeNode(val); //create a new node
            newNode->left = root; //make root the left child of new node
            return newNode;
        }
        preorder(root,val,depth,1);
        return root;
    }
};