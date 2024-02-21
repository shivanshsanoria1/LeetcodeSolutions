class Solution {
public:
    int findLHS(vector<int>& nums) { // T.C.=O(n), S.C.=O(n)
        unordered_map<int, int> mp; // num -> freq
        for(int num: nums)
            mp[num]++;
        int ans = 0;
        for(auto [num1, freq1]: mp)
            if(mp.find(num1 + 1) != mp.end()) // num1 + 1 found in map
                ans = max(ans, freq1 + mp[num1 + 1]);
        return ans;
    }
};