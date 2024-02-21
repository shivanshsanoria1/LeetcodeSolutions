class Solution {
public:
    // returns true if s1 and s2 are anagrams of each other
    bool isAnagram(string& s1, string& s2){
        if(s1.length() != s2.length())
            return false;
        vector<int> freq(26, 0);
        for(char ch: s1)
            freq[ch - 'a']++;
        for(char ch: s2)
            freq[ch - 'a']--;
        for(int i=0; i<26; i++)
            if(freq[i] != 0)
                return false;
        return true;
    }

    vector<string> removeAnagrams(vector<string>& words) {
        vector<string> ans;
        ans.push_back(words[0]);
        for(int i=1; i<words.size(); i++)
            if(!isAnagram(ans.back(), words[i]))
                ans.push_back(words[i]);
        return ans;
    }
};