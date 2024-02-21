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
    int bfs(unordered_map<int, TreeNode*>& mp, TreeNode* startNode){
        unordered_set<int> visited; // keeps track of currently visited nodes
        queue<TreeNode*> q;
        visited.insert(startNode->val);
        q.push(startNode);
        int level = -1;
        while(!q.empty())
        {
            int size = q.size();
            level++;
            while(size--)
            {
                TreeNode* curr = q.front();
                q.pop();
                TreeNode* par = mp[curr->val];
                // parent exists and is unvisited
                if(par && (visited.find(par->val) == visited.end()))
                {
                    visited.insert(par->val);
                    q.push(par);
                }
                // left child exists and is unvisited
                if(curr->left != NULL && (visited.find(curr->left->val) == visited.end()))
                {
                    visited.insert(curr->left->val);
                    q.push(curr->left);
                }
                // right child exists and is unvisited
                if(curr->right != NULL && (visited.find(curr->right->val) == visited.end()))
                {
                    visited.insert(curr->right->val);
                    q.push(curr->right);
                }
            }
        }
        return level;
    }
 
    void dfs(unordered_map<int, TreeNode*>& mp, int start, TreeNode*& startNode, TreeNode* curr, TreeNode* par){
        if(curr == NULL)
            return;
        if(par != NULL) // parent node exists
            mp[curr->val] = par;
        if(curr->val == start) // found the start node
            startNode = curr;
        dfs(mp, start, startNode, curr->left, curr);
        dfs(mp, start, startNode, curr->right, curr);
    }

    int amountOfTime(TreeNode* root, int start) {
        unordered_map<int, TreeNode*> mp; // curr node val -> parent node 
        TreeNode* startNode = NULL;
        dfs(mp, start, startNode, root, NULL);
        return bfs(mp, startNode);
    }
};
/*
# dfs(): fills the map (with curr node val -> parent node) and finds the start node, ie, node with the value 'start'
# bfs(): returns the number of levels taken to visit all the nodes starting from the startNode, 
while moving in 3 directions: left-child, right-child, parent
*/