class Solution {
public:
    // T.C.=O(n), S.C.=O(n)
    int duplicateNumbersXOR(vector<int>& nums) {
        unordered_map<int, int> mp;
        for(int num: nums)
            mp[num]++;
        
        int x = 0;
        for(auto [num, freq]: mp)
            if(freq == 2)
                x ^= num;
        
        return x;
    }
};