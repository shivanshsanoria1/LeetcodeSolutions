class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int n=nums.size(), c=0;
        if(n<3) // no triplets possible
            return 0;
        for(int i=0; i<n-2; i++)
        {
            for(int j=i+1; j<n-1; j++)
            {
                for(int k=j+1; k<n; k++)
                {
                    if(is_triangle(nums[i],nums[j],nums[k]) == 1)
                        c++;
                }
            }
        }
        return c;
    }
    
    int is_triangle(int a, int b, int c)
    {
        if(a < b+c && b < a+c && c < a+b) // sum of 2 sides must be greater than the third side
            return 1;
        return 0;
    }
};