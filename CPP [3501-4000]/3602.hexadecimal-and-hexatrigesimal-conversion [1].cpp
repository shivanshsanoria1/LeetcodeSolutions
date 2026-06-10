class Solution {
private:
    string decimalToBase_X(int num, int base){
        string s = "";
        while(num > 0)
        {
            int rem = num % base;
            s += rem >= 10 ? rem - 10 + 'A' : rem + '0';
            num /= base;
        }

        reverse(s.begin(), s.end());
        return s;
    }

public:
    // T.C.=O(c), S.C.=O(c)
    // c = log16(n^2) + log36(n^3)
    string concatHex36(int n) {
        return decimalToBase_X(n*n, 16) + decimalToBase_X(n*n*n, 36);
    }
};