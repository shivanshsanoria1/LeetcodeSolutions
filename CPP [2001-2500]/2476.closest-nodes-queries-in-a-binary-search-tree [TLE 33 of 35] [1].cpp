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
    // returns the max val <= key, or -1 otherwise
    int findMaxSmaller(TreeNode* curr, int key){
        if(curr == nullptr)
            return -1;
        
        if(curr->val == key)
            return key;

        return curr->val < key ? max(curr->val, findMaxSmaller(curr->right, key)) : min(curr->val, findMaxSmaller(curr->left, key));
    }
    
    // returns the min val >= key, or INT_MAX otherwise
    int findMinLarger(TreeNode* curr, int key){
        if(curr == nullptr)
            return INT_MAX;
        
        if(curr->val == key)
            return key;

        return curr->val > key ? min(curr->val, findMinLarger(curr->left, key)) : max(curr->val, findMinLarger(curr->right, key));
    }

public:
    // T.C.=O(q*n)
    // n: num of nodes in tree, q: size of queries[]
    vector<vector<int>> closestNodes(TreeNode* root, vector<int>& queries) {
        vector<vector<int>> ans;

        for(int query: queries)
        {
            int maxSmaller = findMaxSmaller(root, query);
            int minLarger = findMinLarger(root, query);

            if(minLarger == INT_MAX)
                ans.push_back({maxSmaller, -1});
            else
                ans.push_back({maxSmaller, minLarger});
        }

        return ans;
    }
};
// since the given BST can be unbalanced,
// the height of tree can be 'n' in the worst case