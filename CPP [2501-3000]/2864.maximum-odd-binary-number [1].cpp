class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int ones = 0, zeros = 0;
        for(char ch: s)
        {
            if(ch == '1')
                ones++;
            else
                zeros++;
        }

        string ans = "";
        ones--;
        while(ones--)
            ans += "1";
        while(zeros--)
            ans += "0";
        ans += "1";
        return ans;
    }
};