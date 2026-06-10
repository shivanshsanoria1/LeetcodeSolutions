class Solution {
public:
    int solve(int low, int high, int zero, int one, int curr){
        if(curr > high)
            return 0;
        if(curr == high)
            return 1;
        int left = solve(low, high, zero, one, curr + zero);
        int right = solve(low, high, zero, one, curr + one);
        return curr >= low ? 1 + left + right : left + right;
    }

    int countGoodStrings(int low, int high, int zero, int one) { // Recursion
        return solve(low, high, zero, one, 0);
    }
};