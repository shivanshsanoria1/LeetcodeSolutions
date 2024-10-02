class Solution {
public:
    // T.C.=O(n*log(n)), S.C.=O(n)
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> temp = arr;
        sort(temp.begin(), temp.end());

        // num -> rank
        unordered_map<int, int> mp;
        int rank = 1;
        for(int num: temp)
            if(mp.find(num) == mp.end())
                mp[num] = rank++;
        
        vector<int> ranks;
        for(int num: arr)
            ranks.push_back(mp[num]);
        
        return ranks;
    }
};