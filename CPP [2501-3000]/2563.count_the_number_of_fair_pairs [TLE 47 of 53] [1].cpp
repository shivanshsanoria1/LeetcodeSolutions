class Solution {
public:
    // T.C.=O(n^2), S.C.=O(1)
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        int n=nums.size();
        long long int count = 0;

        for(int i=0; i<n-1; i++)
            for(int j=i+1; j<n; j++)
                if(nums[i] + nums[j] >= lower && nums[i] + nums[j] <= upper)
                    count++;
        
        return count;
    }
};