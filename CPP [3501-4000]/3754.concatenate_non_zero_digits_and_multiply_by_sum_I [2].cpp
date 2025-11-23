class Solution {
public:
    // T.C.=O(1), S.C.=O(1)
    long long sumAndMultiply(int n) {
        long long int numWithoutZeros = 0;
        int digitSum = 0;
        for(long long int mul = 1; n>0; n /= 10){
            int rem = n % 10;
            if(rem == 0)
                continue;

            numWithoutZeros += mul * rem;
            digitSum += rem;

            mul *= 10;
        }

        return numWithoutZeros * digitSum;
    }
};