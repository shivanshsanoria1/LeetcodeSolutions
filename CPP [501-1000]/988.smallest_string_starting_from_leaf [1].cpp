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
    void dfs(TreeNode* curr, string& ans, string& str){
        if(curr == nullptr)
            return;
        
        str += char(curr->val + 'a');

        if(curr->left == nullptr && curr->right == nullptr)
        {
            string revStr = str;
            reverse(revStr.begin(), revStr.end());

            if(ans == "" || revStr < ans)
                ans = revStr;
        }

        dfs(curr->left, ans, str);
        dfs(curr->right, ans, str);

        str.pop_back();
    }

public:
    string smallestFromLeaf(TreeNode* root) {
        string str = "";
        string ans = "";

        dfs(root, ans, str);

        return ans;
    }
};