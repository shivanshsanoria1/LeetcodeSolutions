class Solution {
public:
    long long countBadPairs(vector<int>& nums) { // T.C.=O(n^2), S.C.=O(1)
        int n=nums.size();
        long long int count = 0;
        for(int i=0; i<n-1; i++)
            for(int j=i+1; j<n; j++)
                if(nums[i] - i != nums[j] -j)
                    count++;
        return count;
    }
};