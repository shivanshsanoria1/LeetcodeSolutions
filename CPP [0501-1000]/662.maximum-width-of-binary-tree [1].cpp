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
    int widthOfBinaryTree(TreeNode* root) {
        int max_width = 0;
        TreeNode* curr= NULL;
        queue<pair<TreeNode*, int>> q; // pair<TreeNode*, index>
        q.push({root, 0});
        while(!q.empty())
        {
            int size = q.size();
            int min_index = q.front().second; // min index of node in curr level
            int start_index, end_index; // start and end indexing of nodes in curr level
            for(int i=0; i<size; i++)
            {
                curr = q.front().first;
                long long int index = q.front().second - min_index; // use long long int instead of int 
                q.pop();
                if(i == 0)
                    start_index = index;
                if(i == size-1)
                    end_index = index;
                if(curr->left != NULL) // if parent is at index i then left child at 2*i+1
                    q.push({curr->left, 2*index + 1});
                if(curr->right != NULL) // if parent is at index i then right child at 2*i+2
                    q.push({curr->right, 2*index + 2});
            }
            int curr_width = end_index - start_index + 1;
            max_width = max(max_width, curr_width);
        }
        return max_width;
    }
};