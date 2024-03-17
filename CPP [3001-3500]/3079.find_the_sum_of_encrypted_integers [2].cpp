class Solution {
private:
    int getMaxDigit(int num) {
        string str = to_string(num);
        char maxDigit = '0';
        for(char ch: str)
            maxDigit = max(maxDigit, ch);
        return maxDigit - '0';
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