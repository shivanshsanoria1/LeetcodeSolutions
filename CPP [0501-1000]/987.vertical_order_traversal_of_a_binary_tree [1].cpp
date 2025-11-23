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
        map<int,vector<int>> mp1; //map<col,vector of <node->val>>
        queue<pair<TreeNode*,int>> q; //queue<node,col>
        q.push({root,0}); //root node has col=0
        while(!q.empty()) //similar to level order traversal
        {
            int len=q.size();
            map<int,multiset<int>> mp2; //map<col,multiset of <node->val>>
            while(len--)
            {
                TreeNode *curr= q.front().first;
                int col= q.front().second;
                q.pop();
                mp2[col].insert(curr->val); //insert the popped node value in multiset at position 'col'
                if(curr->left != NULL)
                    q.push({curr->left,col-1});
                if(curr->right != NULL)
                    q.push({curr->right,col+1});
            }
            for(auto it: mp2) //for every col value in map2
                for(auto it2: it.second) //for every node value in each multiset of map2
                    mp1[it.first].push_back(it2);
        }
        for(auto it: mp1)
            ans.push_back(it.second);
        return ans;
    }
};
//multiset is used instead of set to handle the case where different nodes have the same values and the same (x,y) coordinate