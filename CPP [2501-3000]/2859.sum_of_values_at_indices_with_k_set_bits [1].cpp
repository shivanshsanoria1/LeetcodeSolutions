class Solution {
public:
    int setBitsCount(int num){
        int count = 0;
        while(num > 0)
        {
            count += num & 1;
            num = num >> 1;
        }
        return count;
    }

    int sumIndicesWithKSetBits(vector<int>& nums, int k) {
        int sum = 0;
        for(int i=0; i<nums.size(); i++)
            if(setBitsCount(i) == k)
                sum += nums[i];
        return sum;
    }
};