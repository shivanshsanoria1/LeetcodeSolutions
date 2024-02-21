class Solution {
public:
    // T.C.=O(n), S.C.=O(26)
    string sortString(string s) {
        vector<int> freq(26, 0);
        for(char ch: s)
            freq[ch - 'a']++;
        
        string ans = "";
        while(ans.length() < s.length())
        {
            for(int i=0; i<26; i++)
                if(freq[i] > 0)
                {
                    ans += 'a' + i;
                    freq[i]--;
                }
            
            for(int i=25; i>=0; i--)
                if(freq[i] > 0)
                {
                    ans += 'a' + i;
                    freq[i]--;
                }
        }

        return ans;
    }
};