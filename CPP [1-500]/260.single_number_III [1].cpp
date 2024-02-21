class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) { // T.C.=O(n), S.C.=O(n)
        unordered_map<int, int> mp; // num -> freq
        for(int num: nums)
            mp[num]++;
        vector<int> ans;
        for(auto [num, freq]: mp)
            if(freq == 1)
                ans.push_back(num);
        return ans;
    }
};