class Solution {
public:
    // T.C.=O(n), S.C.=O(26)
    string lastNonEmptyString(string s) {
        vector<int> freq(26, 0);
        for(char ch: s)
            freq[ch - 'a']++;
        
        int maxFreq = *max_element(freq.begin(), freq.end());

        string ans = "";
        for(int i=s.length()-1; i>=0; i--)
            if(freq[s[i] - 'a'] == maxFreq)
            {
                ans += s[i];
                freq[s[i] - 'a']--;
            }
        
        reverse(ans.begin(), ans.end());
        return ans;
    }
};