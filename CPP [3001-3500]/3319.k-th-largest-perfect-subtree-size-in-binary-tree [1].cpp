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
    // returns {deepest-leaf-level, size}; level of root is 0
    // deepest-leaf-level: level of the deepest leaf of the subtree
    // (if the subtree rooted at curr is perfect or -1 otherwise)
    // size: size of the subtree 
    // (if the subtree rooted at curr is perfect or 0 otherwise)
    pair<int, int> dfs(TreeNode* curr, int level, int k, priority_queue<int, vector<int>, greater<int>>& pq){
        if(curr == nullptr)
            return {level, 0};
        
        auto [leftLeafLevel, leftSize] = dfs(curr->left, level + 1, k, pq);
        auto [rightLeafLevel, rightSize] = dfs(curr->right, level + 1, k, pq);
        
        // either one of left or right subtrees is not perfect or
        // deepest-leaf-levels of left and right do not match
        if(leftLeafLevel == -1 || rightLeafLevel == -1 || leftLeafLevel != rightLeafLevel)
            return {-1, 0};
        
        pq.push(leftSize + rightSize + 1);
        if(pq.size() == k + 1)
            pq.pop();

        return {leftLeafLevel, leftSize + rightSize + 1};
    }

public:
    // T.C.=O(n*log(k))
    int kthLargestPerfectSubtree(TreeNode* root, int k) {
        // min-heap; maintained at a max-size of k
        priority_queue<int, vector<int>, greater<int>> pq;
        dfs(root, 0, k, pq);

        return pq.size() == k ? pq.top() : -1;
    }
};