class Solution {
public:
    // T.C.=O(log(n^2)), S.C.=O(1)
    int gcdOfOddEvenSums(int n) {
        int sumEven = n*(n+1);
        int sumOdd = sumEven - n;

        return __gcd(sumEven, sumOdd);
    }
};