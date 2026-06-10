class Solution {
public:
    int smallestNumber(int n) {
        int mul = 1;
        while(mul <= n)
            mul *= 2;

        return mul - 1;
    }
};