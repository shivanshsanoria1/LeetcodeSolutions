class Solution {
public:
    int alternateDigitSum(int n) {
        int altSum = 0;
        int digCount = 0;
        while(n > 0)
        {
            digCount++;
            if(digCount % 2 == 1)
                altSum += n % 10;
            else
               altSum -= n % 10; 
            n /= 10; 
        }
        return digCount % 2 == 1 ? altSum : -altSum;
    }
};
/*
# for odd digit num, last digit has +ive sign
(+) (-) (+) (-) ... (+)
# for even digit num, last digit have -ive sign
(+) (-) (+) (-) ... (+) (-)
# here, in the solution we are assuming the last digit has +ive sign, ie, 
total num of digits in the n is odd
# if the total num of digits in the n is even, then we just flip the sign of the sum
*/