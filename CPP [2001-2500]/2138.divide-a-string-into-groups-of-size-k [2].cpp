class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        int n=s.length();
        vector<string> ans;

        string sub = "";
        for(char ch: s)
        {
            sub += ch;
            if(sub.length() == k)
            {
                ans.push_back(sub);
                sub = "";
            }
        }

        if(sub.length() == 0)
            return ans;
            
        string filler = "";
        int fillCount = k - n % k;
        while(fillCount--)
            filler += fill;
            
        sub += filler;
        ans.push_back(sub);
        return ans;
    }
};