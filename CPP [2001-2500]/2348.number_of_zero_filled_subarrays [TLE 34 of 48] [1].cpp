class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) { // T.C.=O(n^2), S.C.=O(1)
        long long int ans = 0;
        int n=nums.size();
        for(int i=0; i<n; i++)
            for(int j=i; j<n; j++)
            {
                if(nums[j] == 0)
                    ans++;
                else
                    break;
            }
        return ans;
    }
};