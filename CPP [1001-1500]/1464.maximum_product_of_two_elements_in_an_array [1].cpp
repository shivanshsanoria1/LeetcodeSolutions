class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int max1 = 0, max2 = 0; // 1st and 2ns max num
        for(int num: nums)
        {
            if(num >= max1)
            {
                max2 = max1;
                max1 = num;
            }
            else if(num > max2)
                max2 = num;
        }
        return (max1 - 1) * (max2 - 1);
    }
};