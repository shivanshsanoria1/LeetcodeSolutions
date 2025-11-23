class Solution {
private:
    int getDigitSum(int num){
        int sum = 0;
        while(num > 0)
        {
            sum += num % 10;
            num /= 10;
        }

        return sum;
    }

public:
    // T.C.=O(??), S.C.=O(1)
    int addDigits(int num) {
        while(true)
        {
            int digitSum = getDigitSum(num);

            if(digitSum < 10)
                return digitSum;
            
            num = digitSum;
        }

        return -1;
    }
};