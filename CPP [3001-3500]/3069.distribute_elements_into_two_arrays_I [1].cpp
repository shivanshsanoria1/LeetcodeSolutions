class Solution {
public:
    // T.C.=O(n), S.C.=O(n)
    vector<int> resultArray(vector<int>& nums) {
        int n=nums.size();
        if(n == 1)
            return nums;

        vector<int> ans, arr2;
        ans.push_back(nums[0]);
        arr2.push_back(nums[1]);

        for(int i=2; i<n; i++)
        {
            if(ans.back() > arr2.back())
                ans.push_back(nums[i]);
            else
                arr2.push_back(nums[i]);
        }

        for(int num: arr2)
            ans.push_back(num);
        return ans;
    }
};