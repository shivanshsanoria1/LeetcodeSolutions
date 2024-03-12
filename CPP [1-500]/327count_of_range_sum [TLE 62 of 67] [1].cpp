class Solution {
public:
    // T.C.=O(n^2), S.C.=O(1)
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        int n=nums.size();
        int count = 0;
        for(int i=0; i<n; i++)
        {
            long long int sum = 0;
            for(int j=i; j<n; j++)
            {
                sum += nums[j];
                if(sum >= lower && sum <= upper)
                    count++;
            }
        }
        return count;
    }
};