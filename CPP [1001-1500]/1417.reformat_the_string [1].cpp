class Solution {
public:
    string reformat(string s) {
        int alphaCount = 0, digCount = 0;
        string alphaStr = "", digStr = "";
        for(char ch: s)
        {
            if(ch >= 'a' && ch <= 'z')
            {
                alphaCount++;
                alphaStr += ch;
            }
            else
            {
                digCount++;
                digStr += ch;
            }
        }

        string ans = "";
        if(abs(alphaCount - digCount) > 1)
            return ans;
        
        int n=s.length();
        int i=0, j=0;
        bool turn = alphaCount >= digCount ? true : false;
        while(n--)
        {
            if(turn)
            {
                ans += alphaStr[i];
                i++;
            }
            else
            {
                ans += digStr[j];
                j++;
            }
            turn = !turn;
        }
        return ans;
    }
};
/*
# bool turn = true: take a char from alphabet-string
# bool turn = false: take a char from digit-string
*/