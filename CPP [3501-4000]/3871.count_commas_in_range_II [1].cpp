class Solution {
public:
    // T.C.=O(1), S.C.=O(1)
    // Math
    long long countCommas(long long n) {
        int digs = to_string(n).length();
        long long mul = 1000;
        long long count = 0;

        for(int d=4; d <= digs; d++, mul *= 10)
            count += (min(n, mul*10 - 1) - mul + 1) * ((d-1)/3);

        return count;
    }
};

/*
# 4,5,6 digit numbers have 1 comma 
# 7,8,9 digit numbers have 2 commas
# 10,11,12 digit numbers have 3 commas
# 13,14,15 digit numbers have 4 commas
# 16 digit numbers have 5 commas
# thus, d digit number has (d-1)/3 commas
*/