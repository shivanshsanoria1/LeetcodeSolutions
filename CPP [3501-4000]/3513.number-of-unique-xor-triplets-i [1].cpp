class Solution {
private:
    // returns min num of bits required to 
    // represent the given num
    int countBits(int num){
        int count = 0;
        while(num > 0)
        {
            count++;
            num >>= 1;
        }

        return count;
    }

public:
    // T.C.=O(log(n)), S.C.=O(1)
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();
        int bitCount = countBits(n);

        return n < 3 ? n : (1 << bitCount);
    }
};

/*
# we can make all the nums in range [1, n] 
  by setting i=j=k, the XOR of triplet becomes
  A ^ A ^ A = A ^ (A ^ A) = A ^ 0 = A
# let b: min num of bits required to represent the max num in nums[]
# we can make any num in range [0, pow(2, b)-1] 
  so a total of pow(2, b) values
# pow(2, b) is the same as (1 << b)
*/