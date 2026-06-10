class Solution {
private:
    int getOriginalNum(int num){
        // pow(2, 10) - 1 = (1023)10 = (1 111 111 111)2
        int mask = (1 << 10) - 1;
        return num & mask;
    }
    
public:
    // T.C.=O(n), S.C.=O(1)
    // bit-manipulation
    // modifying the original vector
    vector<int> buildArray(vector<int>& nums) {
        // storing 2 nums at each position using bit-manipulation
        for(int& num: nums)
            num |= (getOriginalNum(nums[getOriginalNum(num)]) << 10);

        // discard the original num so that only the 
        // updated num remains at each position
        for(int& num: nums)
            num >>= 10;

        return nums;
    }
};

/*
# given, 0 <= nums[i] <= 999
# since, pow(2, 10) = 1024 > 999 > nums[i]
# therefore, nums[i] only need 10 bits to be represented
# the next 10 bits to the left, can be used to represent the updated num
# each num can be seen as 3 segments:
  S3 (21 bits); S2 (10 bits); S1 (10 bits)
  []; [19 ... 11 10]; [9 ... 1 0]
  no use; updated num; original num
*/