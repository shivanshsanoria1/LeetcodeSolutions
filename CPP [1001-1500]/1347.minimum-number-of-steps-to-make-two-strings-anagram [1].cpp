class Solution {
public:
    // T.C.=O(n), S.C.=O(26)
    int minSteps(string s, string t) {
        vector<int> freq(26, 0);
        for(char ch: s)
            freq[ch - 'a']++;
        for(char ch: t)
            freq[ch - 'a']--;
        
        int steps = 0;
        for(int i=0; i<26; i++)
            steps += abs(freq[i]);

        return steps/2;
    }
};