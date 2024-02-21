class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        int n=s.length();
        vector<string> ans;
        for(int i=0; i<n; i += k)
           ans.push_back(s.substr(i, k));

        string filler = "";
        int fillCount = k - n % k;
        while(fillCount--)
            filler += fill;

        if(ans.back().length() < k)
            ans.back() += filler;
        return ans;
    }
};