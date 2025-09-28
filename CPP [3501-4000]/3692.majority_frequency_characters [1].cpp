class Solution {
public:
    // T.C.=O(n), S.C.=O(n)
    string majorityFrequencyGroup(string s) {
        // char -> freq
        vector<int> freq(26, 0);
        for(char ch: s)
            freq[ch - 'a']++;
        
        // freq -> chars
        vector<string> chars(101, "");
        for(int i=0; i<26; i++)
            if(freq[i] > 0)
                chars[freq[i]] += i + 'a';

        int maxGroupSize = 0;
        string ans = "";
        for(int i=100; i>=1; i--)
            if(chars[i].length() > maxGroupSize){
                maxGroupSize = chars[i].length();
                ans = chars[i];
            }

        return ans;
    }
};