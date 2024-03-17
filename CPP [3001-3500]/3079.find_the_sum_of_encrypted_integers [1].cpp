class Solution {
private:
    int getMaxDigit(int num) {
        int maxDigit = 0;
        while(num > 0)
        {
            maxDigit = max(maxDigit, num % 10);
            num /= 10;
        }
        return maxDigit;
    }

    int encrypt(int num) {
        int maxDigit = getMaxDigit(num);
        int res = 0;
        while(num > 0)
        {
            res = res*10 + maxDigit;
            num /= 10;
        }
        return res;
    }

public:
    int sumOfEncryptedInt(vector<int>& nums) {
        int sum = 0;
        for(int num: nums)
            sum += encrypt(num);
        return sum;
    }
};