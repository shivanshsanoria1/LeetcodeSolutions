class Solution {
public:
    // T.C.=O(n*log(n)), S.C.=O(n)
    // without Comparator
    vector<int> frequencySort(vector<int>& nums) {
        // num -> freq
        unordered_map<int, int> mp; 
        for(int num: nums)
            mp[num]++;
        
        // {freq, -1*num}
        vector<pair<int, int>> vec; 
        for(auto [num, freq]: mp)
            vec.push_back({freq, -1*num});
        
        sort(vec.begin(), vec.end());

        vector<int> ans;
        for(auto [freq, num]: vec)
            while(freq--)
                ans.push_back(-1*num);

        return ans;
    }
};