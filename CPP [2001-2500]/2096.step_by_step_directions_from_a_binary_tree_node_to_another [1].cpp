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
    void dfs(TreeNode* curr, int key, string& path, string& currPath){
        if(curr->val == key)
        {
            path = currPath;
            return;
        }

        if(curr->left != nullptr)
        {
            currPath += "L";
            dfs(curr->left, key, path, currPath);
            currPath.pop_back();
        }

        if(curr->right != nullptr)
        {
            currPath += "R";
            dfs(curr->right, key, path, currPath);
            currPath.pop_back();
        }
    }

public:
    // T.C.=O(n), S.C.=O(n)
    string getDirections(TreeNode* root, int startValue, int destValue) {
        string currPath = "";

        // find the path from root to source
        string srcPath = "";
        dfs(root, startValue, srcPath, currPath);
        
        // find the path from root to destination
        string destPath = "";
        dfs(root, destValue, destPath, currPath);

        // move i and j forward until the chars become unequal
        int i = 0, j = 0;
        while(i < srcPath.length() && j < destPath.length() && srcPath[i] == destPath[j])
        {
            i++;
            j++;
        }
        
        string ans = "";
        // replace each char from index i till end with 'U' 
        // in the source-path and append it to the ans
        while(i < srcPath.length())
        {
            ans += "U";
            i++;
        }

        // append the chars from index j till end 
        // in the destination-path to the ans
        while(j < destPath.length())
        {
            ans += destPath[j];
            j++;
        }

        return ans;
    }
};