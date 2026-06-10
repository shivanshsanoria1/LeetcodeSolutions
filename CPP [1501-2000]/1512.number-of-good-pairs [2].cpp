class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) { // T.C.=O(n), S.C.=O(n), double pass
        unordered_map<int, int> mp; // num -> freq
        for(int num: nums)
            mp[num]++;
        int count = 0;
        for(auto [num, freq]: mp)
            count += ((freq-1)*freq)/2;
        return count;
    }
};
/*
for a num with frequency 'f', number of good pairs is the sum:
1 + 2 + 3 + ... + (freq-1) = ((freq-1) * freq) / 2
*/