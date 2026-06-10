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
    typedef TreeNode TN;

    void dfs(TN* curr, TN* parent, vector<TN*>& leaves, unordered_map<TN*, TN*>& parent_mp){
        if(curr == nullptr)
            return;
        
        // leaf-node
        if(curr->left == nullptr && curr->right == nullptr)
            leaves.push_back(curr);
        
        // set the parent of curr node
        parent_mp[curr] = parent;
        
        dfs(curr->left, curr, leaves, parent_mp);
        dfs(curr->right, curr, leaves, parent_mp);
    }

    // returns the num of leaf-nodes within 'limit' distance from the source-node
    int bfs(TN* src, int limit, unordered_map<TN*, TN*>& parent_mp){
        unordered_set<TN*> visited;
        queue<TN*> q;
        visited.insert(src);
        q.push(src);
        int leafCount = 0;

        while(!q.empty() && limit-- >= 0)
        {
            int size = q.size();
            while(size--)
            {
                TN* curr = q.front();
                q.pop();

                // leaf-node which is not the source-node
                if(curr != src && curr->left == nullptr && curr->right == nullptr)
                    leafCount++;

                if(parent_mp[curr] != nullptr && visited.find(parent_mp[curr]) == visited.end())
                {
                    visited.insert(parent_mp[curr]);
                    q.push(parent_mp[curr]);
                }
                if(curr->left != nullptr && visited.find(curr->left) == visited.end())
                {
                    visited.insert(curr->left);
                    q.push(curr->left);
                }
                if(curr->right != nullptr && visited.find(curr->right) == visited.end())
                {
                    visited.insert(curr->right);
                    q.push(curr->right);
                }
            }
        }

        return leafCount;
    }

public:
    // T.C.=O(n^2), S.C.=O(n)
    int countPairs(TreeNode* root, int distance) {
        vector<TN*> leaves;
        // node -> parent-node
        unordered_map<TN*, TN*> parent_mp;
        dfs(root, nullptr, leaves, parent_mp);

        int pairs = 0;
        for(TN* leaf: leaves)
            pairs += bfs(leaf, distance, parent_mp);

        // 'pairs' is divided by 2 since each pair is counted twice
        return pairs/2;
    }
};