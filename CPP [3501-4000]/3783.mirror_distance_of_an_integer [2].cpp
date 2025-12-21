class Solution {
private:
    int reverseNum(int num){
        int revNum = 0;
        while(num > 0){
            revNum *= 10;
            revNum += num % 10;
            num /= 10;
        }

        return revNum;
    }

public:
    int mirrorDistance(int n) {
        return abs(n - reverseNum(n));
    }
};