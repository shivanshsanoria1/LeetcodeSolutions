class Solution {
public:
    int hammingDist(int a, int b) //returns count of the bits where a and b are different
    {
        int c=a^b, set_bits=0;
        while(c>0)
        {
            set_bits+=(c&1);
            c=c>>1;
        }
        return set_bits;
    }
    
    int totalHammingDistance(vector<int>& nums) {
        int n=nums.size(), ans=0;
        for(int i=0; i<n-1; i++)
            for(int j=i+1; j<n; j++)
                ans+=hammingDist(nums[i],nums[j]);
        return ans;
    }
};