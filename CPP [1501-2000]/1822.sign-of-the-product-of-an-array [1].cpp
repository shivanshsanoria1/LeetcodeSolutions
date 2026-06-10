class Solution {
public:
    int arraySign(vector<int>& nums) {
        int neg=0;
        for(int i=0; i<nums.size(); i++)
        {
            if(nums[i]<0) //count num of -ive
                neg++;
            else if(nums[i]==0) //if any element is 0 then the product is 0
                return 0;
        }
        if(neg%2!=0) //odd num of -ive
            return -1;
        return 1;
    }
};