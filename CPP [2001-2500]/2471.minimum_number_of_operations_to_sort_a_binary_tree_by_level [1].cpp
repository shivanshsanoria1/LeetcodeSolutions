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
    int countSwaps(vector<int> vec)
    {
        int count = 0;
        int n = vec.size();
        unordered_map<int, int> mp; // num -> index
        for(int i=0; i<n; i++)
            mp[vec[i]] = i;
        // create a sorted copy of the original vector
        vector<int> vecSorted(vec.begin(), vec.end());
        sort(vecSorted.begin(), vecSorted.end());
        for(int i=0; i<n; i++)
            if(vec[i] != vecSorted[i]) // swap is needed
            {
                count++;
                int incorrectVal = vec[i];
                int correctVal = vecSorted[i];
                // swap the incorrect and correct values in the original vector
                swap(vec[i], vec[mp[correctVal]]);
                // update the indexes in the map after swapping
                mp[incorrectVal] = mp[correctVal];
                mp[correctVal] = i;
            }
        return count;
    }

    int minimumOperations(TreeNode* root) { // T.C.=O(n*logn), S.C.=O(n)
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