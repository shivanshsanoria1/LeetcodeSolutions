class Solution {
public:
    // T.C.=O(n), S.C.=O(n)
    int firstUniqueFreq(vector<int>& nums) {
        // num -> freq
        unordered_map<int, int> mp1;
        for(int num: nums)
            mp1[num]++;
        
        // freq of a num -> freq of freqs 
        unordered_map<int, int> mp2;
        for(const auto& [_, freq]: mp1)
            mp2[freq]++;
        
        for(int num: nums)
            if(mp2[mp1[num]] == 1)
                return num;

        return -1;
    }
};