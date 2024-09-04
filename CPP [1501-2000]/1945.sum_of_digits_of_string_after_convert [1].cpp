class Solution {
private:
    int digitSum(int num){
        int sum = 0;
        while(num > 0)
        {
            sum += num % 10;
            num /= 10;
        }

        return sum;
    }

public:
    int getLucky(string s, int k) {
        int sum = 0;
        for(char ch: s)
            sum += digitSum(ch - 'a' + 1);

        // 1 k got consumed in calculating the sum in for-loop
        while(--k)
        {
            // sum is a single digit number
            if(sum <= 9) 
                break;
            sum = digitSum(sum);
        }

        return sum;
    }
};