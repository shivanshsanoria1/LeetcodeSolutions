class Solution {
public:
    int digitSum(int n)
    {
        int digSum = 0;
        while(n > 0)
        {
            digSum += n % 10;
            n /= 10;
        }
        return digSum;
    }

    int differenceOfSum(vector<int>& nums) {
        int sum = 0;
        int digSum = 0;
        for(int n: nums)
        {
            sum += n;
            digSum += digitSum(n);
        }
        return abs(sum - digSum);
    }
};