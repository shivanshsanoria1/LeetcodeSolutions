class Solution {
public:
    // T.C.=O(n^2), S.C.=O(1)
    long long countSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        // array must have atleast k elements
        if(n < k)
            return 0;
            
        int maxNum = *max_element(nums.begin(), nums.end());
        int maxNumCount = count(nums.begin(), nums.end(), maxNum);
        // max-num appears less than k times in nums[]
        if(maxNumCount < k)
            return 0;

        long long int count = 0;

        for(int i=0; i<n; i++)
        {
            int maxNumCount = 0;
            for(int j=i; j<n; j++)
            {
                if(nums[j] == maxNum)
                    maxNumCount++;
                // all the subarrays starting at index 'i'
                // and ending at index >= j are valid
                if(maxNumCount == k)
                {
                    count += n-j;
                    break;
                }
            }
        }

        return count;
    }
};