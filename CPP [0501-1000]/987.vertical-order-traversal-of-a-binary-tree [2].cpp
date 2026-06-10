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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        if(root==NULL)
            return ans;
        map<int,map<int,multiset<int>>> mp; //map<col,map<row,multiset of node->val>>
        queue<pair<TreeNode*,pair<int,int>>> q; //queue<node,<col,row>>
        q.push({root,{0,0}}); //root node has col=0, row=0
        while(!q.empty())
        {
            TreeNode* curr= q.front().first;
            int col=q.front().second.first;
            int row=q.front().second.second;
            q.pop();
            mp[col][row].insert(curr->val);
            if(curr->left != NULL)
                q.push({curr->left,{col-1,row+1}});
            if(curr->right != NULL)
                q.push({curr->right,{col+1,row+1}});
        }
        for(auto it1: mp) //iterate in col
        {
            vector<int> cols; //vector for each column
            for(auto it2: it1.second) //iterate in row
                for(auto it3: it2.second) //iterate in multiset
                    cols.push_back(it3);
            ans.push_back(cols);
        }
        return ans;
    }
};