class Solution {
public:
    int addDigits(int num) {
        if(num==0) // num is 0
            return 0;
        else if(num%9==0) // num is multiple of 9
            return 9;
        return num%9; // num is not a multiple of 9
    }
};