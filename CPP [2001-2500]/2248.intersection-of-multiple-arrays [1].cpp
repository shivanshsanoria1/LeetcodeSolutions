class Solution {
public:
    vector<int> intersection(vector<vector<int>>& nums) {
        int n = nums.size();
        map<int, int> mp; // num -> freq
        for(auto arr: nums)
            for(int num: arr)
                mp[num]++;
        vector<int> ans;
        for(auto it: mp)
            if(it.second == n)
                ans.push_back(it.first);
        return ans;
    }
};