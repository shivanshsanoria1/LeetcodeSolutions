class Solution {
private:
    int getDigitSum(int num){
        int digitSum = 0;
        while(num > 0)
        {
            digitSum += num % 10;
            num /= 10;
        }

        return digitSum;
    }

public:
    // T.C.=O(n*d), S.C.=O(1)
    // d: max num of digits in a num in nums[]
    int minElement(vector<int>& nums) {
        int minDigitSum = INT_MAX;
        for(int num: nums)
            minDigitSum = min(minDigitSum, getDigitSum(num));
        
        return minDigitSum;
    }
};