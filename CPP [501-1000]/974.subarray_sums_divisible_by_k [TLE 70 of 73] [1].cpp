class Solution {
public:
    // T.C.=O(n^2), S.C.=O(1)
    int subarraysDivByK(vector<int>& nums, int k) {
        int n=nums.size();
        int count = 0;

        for(int i=0; i<n; i++)
        {
            int sum = 0;
            
            for(int j=i; j<n; j++)
            {
                sum += nums[j];
                if(sum % k == 0)
                    count++;
            }
        }

        return count;
    }
};