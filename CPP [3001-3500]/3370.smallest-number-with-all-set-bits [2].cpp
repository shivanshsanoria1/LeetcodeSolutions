class Solution {
public:
    int smallestNumber(int n) {
        double expo = log2(n);
        return (floor(expo) == ceil(expo) ? 2*n : pow(2, ceil(log2(n)))) - 1;
    }
};