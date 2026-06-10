class Solution {
public:
    // T.C.=O(l + 26), S.C.=O(26)
    int minDeletion(string s, int k) {
        vector<int> freq(26, 0);
        for(char ch: s)
            freq[ch - 'a']++;
        
        // stores distinct freqs
        vector<int> nums;
        for(int i=0; i<26; i++)
            if(freq[i] > 0)
                nums.push_back(freq[i]);

        // there are already at most k freqs so no need for deletion 
        int n = nums.size();
        if(n <= k)
            return 0;

        // remove the smallest (n-k) freqs
        sort(nums.begin(), nums.end());

        return accumulate(nums.begin(), nums.begin() + n-k, 0);
    }
};