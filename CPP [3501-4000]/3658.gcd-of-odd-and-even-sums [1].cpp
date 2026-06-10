class Solution {
private:
    int gcd(int a, int b){
        while (b > 0) {
            a %= b;
            swap(a, b);
        }

        return a;
    }

public:
    // T.C.=O(log(n^2)), S.C.=O(1)
    int gcdOfOddEvenSums(int n) {
        int sumEven = n*(n+1);
        int sumOdd = sumEven - n;

        return gcd(sumEven, sumOdd);
    }
};