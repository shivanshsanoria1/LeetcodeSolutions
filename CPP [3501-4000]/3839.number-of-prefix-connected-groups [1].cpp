class Solution {
public:
    // T.C.=O(n*k), S.C.=O(n*k)
    int prefixConnected(vector<string>& words, int k) {
        // prefix of length k -> freq
        unordered_map<string, int> mp;
        for(const string& word: words){
            if(word.length() < k)
                continue;
            
            string prefix = word.substr(0, k);
            mp[prefix]++;
        }

        int groups = 0;
        for(const auto& [_, freq]: mp)
            if(freq > 1)
                groups++;

        return groups;
    }
};