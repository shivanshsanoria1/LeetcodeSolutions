class Solution {
public:
    // T.C.=O(n^2), S.C.=O(1)
    long long countSubarrays(vector<int>& nums, long long k) {
        int n = nums.size();
        long long int count = 0;

        for(int i=0; i<n; i++)
        {
            long long int sum = 0;
            for(int j=i; j<n; j++)
            {
                sum += nums[j];
                if(sum * (j-i+1) < k)
                    count++;
                else
                    break;
            }
        }

        return count;
    }
};