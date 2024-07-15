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
    int findRoot(vector<vector<int>>& descriptions){
        unordered_set<int> possibleRoots;

        // all parent nodes can be the root, 
        // so add them to the set
        for(vector<int>& description: descriptions)
            possibleRoots.insert(description[0]);
        
        // any child node cannot be the root 
        // so remove it from the set
        for(vector<int>& description: descriptions)
            possibleRoots.erase(description[1]);

        // possibleRoots.size() is now 1 
        // only the root node remains in the set
        return *possibleRoots.begin();
    }

public:
    // T.C.=O(n), S.C.=O(n)
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        // node val -> node
        unordered_map<int, TreeNode*> mp;

        for(vector<int>& description: descriptions)
        {
            int parent = description[0];
            int child = description[1];
            int isLeft = description[2];

            // no node corresponding to 'parent' found
            // so create a new one
            if(mp.find(parent) == mp.end())
                mp[parent] = new TreeNode(parent);

            // no node corresponding to 'child' found
            // so create a new one
            if(mp.find(child) == mp.end())
                mp[child] = new TreeNode(child);
            
            // link the 'parent' and 'child' nodes
            if(isLeft)
                mp[parent]->left = mp[child];
            else
                mp[parent]->right = mp[child];
        }

        int root = findRoot(descriptions);
        return mp[root];
    }
};