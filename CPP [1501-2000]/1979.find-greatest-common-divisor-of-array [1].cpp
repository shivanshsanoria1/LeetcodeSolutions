class Solution {
public:
    int gcd(int a, int b)
    {
        while(a!=b)
        {
            if(a>=b)
                a=a-b;
            else
                b=b-a;
        }
        return a;
    }
    
    int findGCD(vector<int>& nums) {
        int min_val=INT_MAX, max_val=INT_MIN;
        for(int i=0; i<nums.size(); i++)
        {
            if(nums[i] < min_val)
                min_val=nums[i];
            if(nums[i] > max_val)
                max_val=nums[i];
        }
        return gcd(min_val,max_val);
    }
};