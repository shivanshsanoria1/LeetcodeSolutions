/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void buildParentMap(unordered_map<int, TreeNode*>& parent, TreeNode* root){ // BFS
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            int size = q.size();
            while(size--)
            {
                TreeNode* curr = q.front();
                q.pop();
                if(curr->left != NULL)
                {
                    q.push(curr->left);
                    parent[curr->left->val] = curr;
                }
                if(curr->right != NULL)
                {
                    q.push(curr->right);
                    parent[curr->right->val] = curr;
                }
            }
        }
    }
    
    vector<int> bfs(unordered_map<int, TreeNode*>& parent, TreeNode* target, int k){
        queue<TreeNode*> q;
        unordered_set<int> visited;
        visited.insert(target->val); // mark the target as visited
        q.push(target);
        int dist = 0;
        while(!q.empty() && dist < k)
        {
            int size = q.size();
            while(size--)
            {
                TreeNode* curr = q.front();
                q.pop();
                // left child exists and is unvisited
                if(curr->left != NULL && visited.find(curr->left->val) == visited.end()) 
                {
                    visited.insert(curr->left->val); // mark the left child as visited
                    q.push(curr->left);
                }
                // right child exists and is unvisited
                if(curr->right != NULL && visited.find(curr->right->val) == visited.end()) 
                {
                    visited.insert(curr->right->val); // mark the right child as visited
                    q.push(curr->right);
                }
                // parent exists and is unvisited
                if(parent[curr->val] && visited.find(parent[curr->val]->val) == visited.end()) 
                {
                    visited.insert(parent[curr->val]->val); // mark the parent as visited
                    q.push(parent[curr->val]);
                }
            }
            dist++;
        }
        
        vector<int> ans;
        while(!q.empty())
        {
            TreeNode* curr = q.front();
            q.pop();
            ans.push_back(curr->val);
        }
        return ans;
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<int, TreeNode*> parent; // child node val -> parent node
        buildParentMap(parent, root);
        return bfs(parent, target, k);
    }
};
// all the node values in tree are distinct