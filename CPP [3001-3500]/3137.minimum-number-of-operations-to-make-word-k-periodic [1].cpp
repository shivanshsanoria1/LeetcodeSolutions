class Solution {
public:
    // T.C.=O(n), S.C.=O(n)
    int minimumOperationsToMakeKPeriodic(string word, int k) {
        int n=word.length();

        // substring (of length k) -> freq
        unordered_map<string, int> mp;

        for(int i=0; i<n; i += k)
            mp[word.substr(i, k)]++;

        int maxFreq = 0;

        for(auto it: mp)
            maxFreq = max(maxFreq, it.second);
        
        return n/k - maxFreq;
    }
};