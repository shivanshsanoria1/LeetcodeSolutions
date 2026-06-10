class Solution {
public:
    long long removeZeros(long long n) {
        string str = to_string(n);
        string ans = "";
        for(char ch: str)
            if(ch != '0')
                ans += ch;

        return stol(ans);
    }
};