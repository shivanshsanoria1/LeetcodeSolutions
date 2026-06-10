class Solution {
private:
    string getHash(vector<int>& domino){
        int a = domino[0], b = domino[1];

        return to_string(min(a, b)) + "#" + to_string(max(a, b));
    }

public:
    // T.C.=O(n + 100), S.C.=O(100)
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        // domino hash -> freq
        unordered_map<string, int> mp;
        for(vector<int>& domino: dominoes)
            mp[getHash(domino)]++;
        
        int count = 0;
        for(auto [hash, freq]: mp)
            // x equivalent elements will generate xC2= (x*(x-1))/2 pairs
            count += (freq*(freq-1)) / 2;

        return count;
    }
};