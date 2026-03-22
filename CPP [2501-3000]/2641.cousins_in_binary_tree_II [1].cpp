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
    TreeNode* replaceValueInTree(TreeNode* root) {
        // {curr node, sibling val}; (0 if sibling does not exist)
        queue<pair<TreeNode*, int>> q; 
        q.push({root, 0});

        while(!q.empty())
        {
            int size = q.size();
            int levelSum = 0;
            vector<pair<TreeNode*, int>> temp;

            while(size--)
            {
                auto [curr, sibVal] = q.front();
                q.pop();

                levelSum += curr->val;
                temp.push_back({curr, sibVal});

                if(curr->left != nullptr)
                    q.push({curr->left, curr->right != nullptr ? curr->right->val : 0});
                
                if(curr->right != nullptr)
                    q.push({curr->right, curr->left != nullptr ? curr->left->val : 0});
            }

            for(auto [curr, sibVal]: temp)
                curr->val = levelSum - curr->val - sibVal;
        }

        return root;
    }
};