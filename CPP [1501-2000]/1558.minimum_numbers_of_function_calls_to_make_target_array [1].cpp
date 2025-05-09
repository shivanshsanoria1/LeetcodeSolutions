class Solution {
private:
    // returns the num of set bits in 'num'
    int setBitCount(int num){
        int count = 0;
        while(num > 0)
        {
            count += (num & 1);
            num >>= 1;
        }

        return count;
    }

    // returns the min num of bits required to represent the 'num'
    int findMinBits(int num){
        int count = 0;
        while(num > 0)
        {
            count++;
            num >>= 1;
        }

        return count;
    }

public:
    // T.C.=O(n*log(m))
    // m: max val in nums[]
    int minOperations(vector<int>& nums) {
        int ops = 0;
        for(int num: nums)
            ops += setBitCount(num);
        
        int maxVal = *max_element(nums.begin(), nums.end());
        if(maxVal > 0)
            ops += findMinBits(maxVal) - 1;

        return ops;
    }
};

/*
# op_0: adds 1 at a num
# op_1: multiplies each num in nums[] by 2 
# think of every num in its binary form
# op_0: intoduces a bit in binary
# op_1: left-shifts the num by 1 position
# the total num of set bits for each num in nums[] 
  is the num of op_0 needed
# the position of the MSB of the max num in nums[] 
  represents the num of op_1 needed
*/