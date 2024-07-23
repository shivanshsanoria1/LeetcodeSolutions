class Solution {
private:
    static bool cmp(pair<int, int> &a, pair<int, int> &b){
        return a.second == b.second ? a.first > b.first : a.second < b.second;
    }

public:
    // T.C.=O(n*log(n)), S.C.=O(n)
    vector<int> frequencySort(vector<int>& nums) {
        // num -> freq
        unordered_map<int, int> mp; 
        for(int num: nums)
            mp[num]++;
        
        // {num, freq}
        vector<pair<int, int>> vec; 
        for(auto [num, freq]: mp)
            vec.push_back({num, freq});
        
        sort(vec.begin(), vec.end(), cmp);

        vector<int> ans;
        for(auto [num, freq]: vec)
            while(freq--)
                ans.push_back(num);

        return ans;
    }
};