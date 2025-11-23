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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> avg;
        if(root==NULL) // tree is empty
            return avg;
        TreeNode *curr;
        queue<TreeNode*> qu;
        qu.push(root);
        while(!qu.empty())
        {
            int len=qu.size(), n=len; // no. of elements in a level
            double sum=0;
            while(len--)
            {
                curr=qu.front();
                qu.pop();
                sum=sum+curr->val;
                if(curr->left!=NULL) // if left child exists
                    qu.push(curr->left); // push the left child in queue
                if(curr->right!=NULL) // if right child exists
                    qu.push(curr->right); // push the right child in queue
            }
            sum=sum/n; // get the average of each level
            avg.push_back(sum);
        }
        return avg;
    }
};