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
        int ans = 0;
        for(int n: nums)
        {
            ans += n;
            ans -= digitSum(n);
        }
        return abs(ans);
    }
};