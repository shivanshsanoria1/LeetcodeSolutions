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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> levels;
        if(root == NULL) //tree is empty
            return levels;
        queue<TreeNode*> q;
        q.push(root); //push the root node in queue
        while(!q.empty())
        {
            vector<int> level;
            int size = q.size(); //find the size of curr level
            while(size--) //until the size of curr level becomes 0
            {
                TreeNode *curr = q.front();
                q.pop();
                if(curr->left != NULL) //if left child exists
                    q.push(curr->left); //push the left child in queue
                if(curr->right != NULL)  //if right child exists
                    q.push(curr->right); //push the right child in queue
                level.push_back(curr->val); //push the value of node popped from queue in the 'level' vector
            }
            levels.push_back(level); //push the 'level' vector in the 'levels' vector
        }
        return levels;
    }
};