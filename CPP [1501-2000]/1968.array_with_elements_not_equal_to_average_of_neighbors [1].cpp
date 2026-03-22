class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) { // Greedy, T.C.=O(n*logn), S.C.=O(n)
        sort(nums.begin(), nums.end());
        int n=nums.size();
        vector<int> ans;
        int left = 0, right = n % 2 == 0 ? n/2 : (n+1)/2;
        while(right < n)
        {
            ans.push_back(nums[left]);
            left++;
            ans.push_back(nums[right]);
            right++;
        }
        if(n % 2 == 1) // middle element for odd length array
            ans.push_back(nums[left]);
        return ans;
    }
};
/*
# 1,2,3,4,5 -> 1,4,2,5,3
# 1,2,3,4,5,6 -> 1,4,2,5,3,6
*/