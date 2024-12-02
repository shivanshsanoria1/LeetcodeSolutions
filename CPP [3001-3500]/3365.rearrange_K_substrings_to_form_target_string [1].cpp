class Solution {
private:
    // splits the string 's' into equal segments of length s.length()/k
    void tokenize(string& s, int k, unordered_map<string, int>& mp){
        string token = "";
        for(char ch: s)
        {
            token += ch;
            if(token.length() == s.length()/k)
            {
                mp[token]++;
                token = "";
            }
        }
    }

public:
    // T.C.=O(n), S.C.O(n)
    // n: length of 's' and 't'
    bool isPossibleToRearrange(string s, string t, int k) {
        // token -> freq
        unordered_map<string, int> mp;
        tokenize(s, k, mp);

        string token = "";
        for(char ch: t)
        {
            token += ch;
            if(token.length() == t.length()/k)
            {
                if(mp.find(token) == mp.end())
                    return false;
                if(--mp[token] == 0)
                    mp.erase(token);
                token = "";
            }
        }

        return true;
    }
};