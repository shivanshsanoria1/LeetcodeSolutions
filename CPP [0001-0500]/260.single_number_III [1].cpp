class Solution {
public:
    // T.C.=O(n), S.C.=O(n)
    // unordered-map
    vector<int> singleNumber(vector<int>& nums) { 
        // num -> freq
        unordered_map<int, int> mp; 
        for(int num: nums)
            mp[num]++;

        vector<int> ans;
        for(auto [num, freq]: mp)
            if(freq == 1)
                ans.push_back(num);
                
        return ans;
    }
};