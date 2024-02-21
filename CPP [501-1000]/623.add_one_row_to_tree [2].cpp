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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) { //BFS
        if(depth==1)
        {
            TreeNode* newNode = new TreeNode(val); //create a new node
            newNode->left = root; //make root the left child of new node
            return newNode;
        }
        int curr_depth=0;
        TreeNode *curr, *temp;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            int size= q.size();
            curr_depth++;
            while(size--)
            {
                curr=q.front();
                q.pop();
                if(curr_depth == depth-1)
                {
                    TreeNode* new_left_node = new TreeNode(val); //create new left node
                    temp = curr->left; //temp points to the curr left child
                    curr->left = new_left_node; //make new node the left child of curr
                    new_left_node->left = temp; //make old left child the left child of new node

                    TreeNode* new_right_node = new TreeNode(val); //create new right node
                    temp = curr->right; //temp points to the curr right child
                    curr->right = new_right_node; //make new node the right child of curr
                    new_right_node->right = temp; //make old right child the right child of new node
                }
                if(curr->left!=NULL)
                    q.push(curr->left);
                if(curr->right!=NULL)
                    q.push(curr->right);
            }
        }
        return root;
    }
};