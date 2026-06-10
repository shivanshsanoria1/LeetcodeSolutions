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
    typedef long long int lli;

public:
    // T.C.=O(n + h*log(min(k, h))), S.C.=O(min(k, h))
    // n: num of nodes in tree, h: height of tree (num of levels)
    // in the worst-case h = n and k = n
    long long kthLargestLevelSum(TreeNode* root, int k) {
        queue<TreeNode*> q;
        q.push(root);
        // min-heap
        priority_queue<lli, vector<lli>, greater<lli>> pq;

        while(!q.empty())
        {
            int size = q.size();
            lli levelSum = 0;

            while(size--) 
            {
                TreeNode* curr = q.front();
                q.pop();

                levelSum += curr->val;

                if(curr->left != nullptr)
                    q.push(curr->left); 
                if(curr->right != nullptr)
                    q.push(curr->right);
            }

            pq.push(levelSum);

            if(pq.size() == k+1)
                pq.pop();
        }

        return pq.size() < k ? -1 : pq.top();
    }
};