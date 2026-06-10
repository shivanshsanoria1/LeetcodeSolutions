class Solution {
private:
    // returns false if freq of any char is in range (0, k)
    // (both exclusive), and true otherwise
    bool check(vector<int>& freq, int k) {
        for(int i=0; i<26; i++)
            if(freq[i] > 0 && freq[i] < k)
                return false;
        return true;
    }

public:
    // T.C.=O(26*n^2), S.C.=O(26)
    int longestSubstring(string s, int k) {
        int n=s.length();
        int maxLen = 0;

        for(int i=0; i<n; i++)
        {
            vector<int> freq(26, 0);
            
            for(int j=i; j<n; j++)
            {
                freq[s[j] - 'a']++;

                if(check(freq, k))
                    maxLen = max(maxLen, j-i+1);
            }
        }

        return maxLen;
    }
};