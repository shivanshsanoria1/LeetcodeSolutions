class Solution {
public:
    vector<int> numberOfPairs(vector<int>& nums) { //T.C.=O(n), S.C.=O(n)
        vector<int> ans(2, 0);
        unordered_map<int, int> mp;
        for(int num: nums)
            mp[num]++;
        for(auto it: mp)
        {
            ans[0] += it.second/2;
            if(it.second % 2 == 1) // odd freq
                ans[1]++;
        }
        return ans;
    }
};