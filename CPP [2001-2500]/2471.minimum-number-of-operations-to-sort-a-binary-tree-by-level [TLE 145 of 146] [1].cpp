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
    int countSwaps(vector<int> vec) // using selection sort
    {
        int count = 0;
        int n = vec.size();
        for(int i=0; i<n-1; i++)
        {
            int minIdx = i;
            for(int j=i+1; j<n; j++)
                if(vec[j] < vec[minIdx])
                    minIdx = j;
            if(minIdx != i)
            {
                swap(vec[i], vec[minIdx]);
                count++;
            }
        }
        return count;
    }

    int minimumOperations(TreeNode* root) { // T.C.=O(n^2), S.C.=O(n)
        int ans = 0;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            int size = q.size();
            vector<int> levelArr;
            while(size--)
            {
                TreeNode* curr = q.front();
                q.pop();
                if(curr->left != NULL)
                    q.push(curr->left);
                if(curr->right != NULL)
                    q.push(curr->right);
                levelArr.push_back(curr->val);
            }
            ans += countSwaps(levelArr);
        }
        return ans;
    }
};