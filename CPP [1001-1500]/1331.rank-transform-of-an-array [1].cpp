class Solution {
public:
    // T.C.=O(n*log(n)), S.C.=O(n)
    vector<int> arrayRankTransform(vector<int>& arr) {
        // num -> rank
        map<int, int> mp;
        for(int num: arr)
            mp[num] = 0;

        int rank = 1;
        for(auto& it: mp)
            it.second = rank++;

        vector<int> ranks;
        for(int num: arr)
            ranks.push_back(mp[num]);
        
        return ranks;
    }
};