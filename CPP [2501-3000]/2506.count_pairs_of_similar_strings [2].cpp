class Solution {
public:
    int similarPairs(vector<string>& words) { // T.C.=O(26*n), S.C.=O(n)
        unordered_map<string, int> mp; // hash -> freq
        for(int i=0; i<words.size(); i++)
        {
            vector<bool> vec(26, false);
            for(char ch: words[i])
                vec[ch - 'a'] = true;
            string hash = "";
            for(int j=0; j<26; j++)
                hash += vec[j] ? '1' : '0';
            mp[hash]++; 
        }
        int count = 0;
        for(auto it: mp)
            count += ((it.second - 1) * it.second) / 2;
        return count;
    }
};