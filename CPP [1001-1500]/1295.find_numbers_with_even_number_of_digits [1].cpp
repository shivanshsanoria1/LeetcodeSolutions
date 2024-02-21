class Solution {
public:
    int numOfDigits(int n)
    {
        int dig=0;
        while(n>0)
        {
            dig++;
            n/=10;
        }
        return dig;
    }
    
    int findNumbers(vector<int>& nums) {
        int c=0;
        for(int i=0; i<nums.size(); i++)
            if(numOfDigits(nums[i])%2 == 0) //has even num of digits
                c++;
        return c;
    }
};