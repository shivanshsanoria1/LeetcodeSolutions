class Solution {
public:
    // T.C.=O(n), S.C.=O(n)
    int findLHS(vector<int>& nums) { 
        // num -> freq
        unordered_map<int, int> mp; 
        for(int num: nums)
            mp[num]++;

        int ans = 0;
        for(auto [num1, freq1]: mp)
            if(mp.find(num1 + 1) != mp.end())
                ans = max(ans, freq1 + mp[num1 + 1]);

        return ans;
    }
};