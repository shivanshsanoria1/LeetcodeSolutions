class Solution {
public:
    // T.C.=O(n^2), S.C.=O(1)
    long long countAlternatingSubarrays(vector<int>& nums) {
        int n=nums.size();
        long long int count = 0;

        for(int i=0; i<n-1; i++)
            for(int j=i+1; j<n; j++)
            {
                if(nums[j] == nums[j-1])
                    break;
                count++;
            }

        return n + count;
    }
};
// n is added to count at the end because each subarray of size 1 is always alternating