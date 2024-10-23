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
    void dfs(TreeNode* curr, int parentVal, int level, int x, int y, pair<int, int>& parents, pair<int, int>& levels){
        if(curr == nullptr)
            return;
        
        auto& [parentValX, parentValY] = parents;
        auto& [levelX, levelY] = levels;

        if(curr->val == x)
        {
            parentValX = parentVal;
            levelX = level;
        }
        else if(curr->val == y)
        {
            parentValY = parentVal;
            levelY = level;
        }

        // parents of both x and y are found
        if(parentValX != -1 && parentValY != -1)
            return;

        dfs(curr->left, curr->val, level + 1, x, y, parents, levels);
        dfs(curr->right, curr->val, level + 1, x, y, parents, levels);
    }

public:
    bool isCousins(TreeNode* root, int x, int y) {
        // {parent-val of x, parent-val of y}
        pair<int, int> parents;
        // {level x, level y}
        pair<int, int> levels;

        parents.first = -1;
        parents.second = -1;
        levels.first = -1;
        levels.second = -1;

        dfs(root, -1, 0, x, y, parents, levels);

        return parents.first != parents.second && levels.first == levels.second;
    }
};

// Cousins: 2 nodes on the same level but having different parents