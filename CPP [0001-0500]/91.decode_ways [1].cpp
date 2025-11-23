class Solution {
public:
    int numDecodings(string s) {
        int n=s.length();
        if(n == 0 || s[0] == '0')
            return 0;
        // c1: count upto current (digit-1), c2: count upto current (digit-2)
        int c1 = 1, c2 = 1; 
        for(int i=1; i<n; i++)
        {
            // current digit is taken as single digit number
            int d = s[i] - '0'; 
            // current digit and previous digit is taken as double digit number
            int dd = 10*(s[i-1] - '0') + d; 
            int c = 0;
            if(d > 0)
                c += c1;
            if(dd >= 10 && dd <= 26)
                c += c2;
            c2 = c1;
            c1 = c;
        }
        return c1;
    }
};