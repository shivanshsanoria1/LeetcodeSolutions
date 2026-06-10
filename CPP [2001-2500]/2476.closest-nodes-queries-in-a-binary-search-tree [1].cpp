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
    void inorder(TreeNode* curr, vector<int>& nums){
        if(curr == nullptr)
            return;
    
        inorder(curr->left, nums);
        nums.push_back(curr->val);
        inorder(curr->right, nums);
    }

    // returns the max val <= key, or -1 otherwise
    int findMaxSmaller(vector<int>& nums, int key){
        int left = 0, right = nums.size()-1;
        int res = -1;

        while(left <= right)
        {
            int mid = left + (right - left)/2;

            if(nums[mid] == key)
                return key;
            else if(nums[mid] < key)
            {
                res = nums[mid];
                left = mid + 1;
            }
            else // nums[mid] > key
                right = mid - 1;
        }

        return res;
    }

    // returns the min val >= key, or -1 otherwise
    int findMinLarger(vector<int>& nums, int key){
        int left = 0, right = nums.size()-1;
        int res = -1;

        while(left <= right)
        {
            int mid = left + (right - left)/2;

            if(nums[mid] == key)
                return key;
            else if(nums[mid] > key)
            {
                res = nums[mid];
                right = mid - 1;
            }
            else // nums[mid] < key
                left = mid + 1;
        }

        return res;
    }

public:
    // T.C.=O(q*log(n))
    // n: num of nodes in tree, q: size of queries[]
    vector<vector<int>> closestNodes(TreeNode* root, vector<int>& queries) {
        vector<int> nums;
        inorder(root, nums);

        vector<vector<int>> ans;

        for(int query: queries)
        {
            int maxSmaller = findMaxSmaller(nums, query);
            
            // 'query' found in nums[]
            if(maxSmaller == query)
                ans.push_back({query, query});
            // 'query' not found in nums[]
            else
            {
                int minLarger = findMinLarger(nums, query);
                ans.push_back({maxSmaller, minLarger});
            }
        }

        return ans;
    }
};