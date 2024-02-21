class Solution {
public:
    int subarraySum(vector<int>& nums, int k) { //T.C.=O(n^2) ; S.C.=O(1)
        int n=nums.size(), c=0;
        for(int i=0; i<n; i++)
        {
            int sum=0;
            for(int j=i; j<n; j++)
            {
                sum+=nums[j];
                if(sum==k)
                    c++;
            }
        }
        return c;
    }
};