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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if(root==NULL)
            return ans;
        TreeNode* curr;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            int size= q.size();
            while(size--)
            {
                curr= q.front();
                if(size==0) //last node of the level
                    ans.push_back(curr->val);
                q.pop();
                if(curr->left!=NULL) //if left child exists
                    q.push(curr->left);
                if(curr->right!=NULL) //if right child exists
                    q.push(curr->right);
            }
        }
        return ans;
    }
};
//use level order traversal and push the value of last node for each level in the ans