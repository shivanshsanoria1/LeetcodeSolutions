class Solution {
public:
    // T.C.=O(n^2), S.C.=O(1)
    long long countPairs(vector<int>& nums, int k) {
        int n=nums.size();
        long long int count = 0;

        for(int i=0; i<n-1; i++)
            for(int j=i+1; j<n; j++)
                if(((long long int)nums[i] * nums[j]) % k == 0)
                    count++;

        return count;
    }
};