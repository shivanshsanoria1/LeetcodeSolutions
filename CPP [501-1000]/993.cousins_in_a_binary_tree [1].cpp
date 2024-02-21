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
    int parValX = -1, parValY = -1; // parent values of nodes with value x and y
    int levelX = -1, levelY = -1; // level values of nodes with value x and y
    bool areCousin = false;

public:
    void dfs(TreeNode* curr, int parVal, int level, int x, int y){
        if(curr == NULL)
            return;
        if(curr->val == x) // found node with val x
        {
            parValX = parVal;
            levelX = level;
        }
        else if(curr->val == y) // found node with val y
        {
            parValY = parVal;
            levelY = level;
        }
        if(levelX > 0 && levelY > 0) // both x and y nodes are found
        {
            if(levelX == levelY && parValX != parValY)
                areCousin = true;
            return;
        } 
        dfs(curr->left, curr->val, level + 1, x, y);
        dfs(curr->right, curr->val, level + 1, x, y);
    }

    bool isCousins(TreeNode* root, int x, int y) {
        dfs(root, -1, 0, x, y); 
        return areCousin;
    }
};
// root has no parent val so -1 is used
// start the level at 0