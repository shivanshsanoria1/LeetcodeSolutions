class Solution {
private:
    // returns true if all chars have freq >= k,
    // and false otherwise (0 freq chars are ignored)
    bool checkAllCharsHaveFreqAtleast_k(vector<int>& freq, int k) {
        for(int i=0; i<26; i++)
            if(freq[i] > 0 && freq[i] < k)
                return false;
        return true;
    }

    // returns the max length of substring of 's' having exactly 'uniqueCount'
    // unique chars and the freq of each char is >= k
    int getMaxLengthSubtring(string& s, int k, int uniqueCount) {
        vector<int> freq(26, 0);
        int left = 0, right = 0;
        int currUniqueCount = 0;
        int maxLen = 0;

        while(right < s.length())
        {
            // new unique char is being added to window
            if(freq[s[right] - 'a'] == 0)
                currUniqueCount++;
            // expand the window
            freq[s[right] - 'a']++;

            // shrink the window until it becomes valid
            while(currUniqueCount > uniqueCount)
            {
                freq[s[left] - 'a']--;
                // window has lost a unique char
                if(freq[s[left] - 'a'] == 0)
                    currUniqueCount--;
                left++;
            }

            // maximize the window size if 
            // all chars in it have freq >= k 
            if(checkAllCharsHaveFreqAtleast_k(freq, k))
                maxLen = max(maxLen, right - left + 1);

            right++;
        }

        return maxLen;
    }

    // returns the num of unique chars in 's'
    int getUniqueCount(string& s) {
        // mark the chars found in 's' as visited
        vector<bool> visited(26, false);
        for(char ch: s)
            visited[ch - 'a'] = true;

        // num of unique chars in 's'
        int uniqueCount = 0;
        for(int i=0; i<26; i++)
            if(visited[i])
                uniqueCount++;
        
        return uniqueCount;
    }

public:
    // T.C.=O(26*n*26), S.C.=O(26)
    // Sliding-window
    int longestSubstring(string s, int k) {
        int uniqueCount = getUniqueCount(s);
        
        // compute the ans, when the ans substring 
        // has exactly 'u' unique chars
        int maxLen = 0;
        for(int u=1; u <= uniqueCount; u++)
            maxLen = max(maxLen, getMaxLengthSubtring(s, k, u));
        return maxLen;
    }
};