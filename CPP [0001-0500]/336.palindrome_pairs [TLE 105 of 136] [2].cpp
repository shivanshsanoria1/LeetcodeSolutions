class Solution {
private:
    // returns a string s2 of length n2 such that (s1 + s2) is palindrome
    // and "#" if no such string is found
    string findPalindromePartner(string& s1, int n2) {
        int n1=s1.length();
        string s2(n2, '#');

        string s = s1 + s2;
        int left = 0, right = s.length()-1;

        while(left < right)
        {
            if(s[left] != '#' && s[right] != '#' && s[left] != s[right])
                return "#";
            else if(s[left] != '#' && s[right] == '#')
                s[right] = s[left];

            left++;
            right--;
        } 

        // s2 cannot be the same as s1
        return s.substr(n1) == s1 ? "#" : s.substr(n1);
    }

    // returns true if string 's' is palindrome
    bool isPalindrome(string s) {
        int left = 0, right = s.length()-1;
        while(left < right)
        {
            if(s[left] != s[right])
                return false;

            left++;
            right--;
        }
        return true;
    }

    // an empty-word can form a pair with any word which is palindrome
    void emptyWordCaseHandler(vector<string>& words, vector<vector<int>>& ans) {
        int emptyWordIdx = -1;

        for(int i=0; i<words.size(); i++)
            if(words[i] == "")
            {
                emptyWordIdx = i;
                break;
            }
        
        // empty word not found
        if(emptyWordIdx == -1)
            return;

        for(int i=0; i<words.size(); i++)
            // curr word is non-empty and is palindrome 
            if(i != emptyWordIdx && isPalindrome(words[i]))
            {
                ans.push_back({i, emptyWordIdx});
                ans.push_back({emptyWordIdx, i});
            }
    }

public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        // word.length -> { word -> index }
        unordered_map<int, unordered_map<string, int>> mp;
        for(int i=0; i<words.size(); i++)
            mp[words[i].length()][words[i]] = i;

        int maxLen = 0;
        for(string& word: words)
            maxLen = max(maxLen, (int)word.length());

        vector<vector<int>> ans;

        emptyWordCaseHandler(words, ans);

        for(int i=0; i<words.size(); i++)
        {
            int n1 = words[i].length();
            // skip the empty word
            if(n1 == 0)
                continue;

            for(int n2=1; n2 <= maxLen; n2++)
            {
                // word of length n2 not found
                if(mp.find(n2) == mp.end())
                    continue;

                if(n1 >= n2)
                {
                    string partner = findPalindromePartner(words[i], n2);

                    if(partner == "#")
                        continue;

                    if(mp[n2].find(partner) != mp[n2].end())
                        ans.push_back({i, mp[n2][partner]});
                }
                else // n1 < n2
                {
                    // check every word of length n2, if it forms
                    // a pair with the ith word
                    for(auto [word, j]: mp[n2])
                        if(i != j && isPalindrome(words[i] + word))
                            ans.push_back({i, j});
                }
            }
        }

        return ans;
    }
};