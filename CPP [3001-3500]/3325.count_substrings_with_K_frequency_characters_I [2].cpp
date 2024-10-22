class Solution {
public:
    // T.C.=O(n*26), S.C.=O(26)
    // Sliding-window
    int numberOfSubstrings(string s, int k) {
        vector<int> freq(26, 0);
        int n = s.length();
        int left = 0, right = 0;
        int count = 0;

        while(right < n)
        {
            freq[s[right] - 'a']++;

            while(*max_element(freq.begin(), freq.end()) == k)
            {
                // all the substrings in index-range 
                // [right, n-1] are valid
                count += n - right;

                freq[s[left] - 'a']--;
                left++;
            }

            right++;
        }

        return count;
    }
};