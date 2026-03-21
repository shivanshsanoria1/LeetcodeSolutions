class Solution {
public:
    // T.C.=O(n^2), S.C.=O(1)
    long long continuousSubarrays(vector<int>& nums) { 
        int n=nums.size();
        long long int count = 0;
        for(int i=0; i<n; i++)
        {
            int maxVal = INT_MIN;
            int minVal = INT_MAX;
            for(int j=i; j<n; j++)
            {
                maxVal = max(maxVal, nums[j]);
                minVal = min(minVal, nums[j]);
                if(maxVal - minVal > 2)
                    break;
                count++;
            }
        }
        return count;
    }
};