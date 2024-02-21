class Solution {
public:
    int repeatedNTimes(vector<int>& nums) { // T.C=O(n), S.C.=O(n)
        int n = nums.size();
        unordered_map<int, int> mp; // num -> freq
        for(int num: nums)
            mp[num]++;
        for(auto it: mp)
            if(it.second == n/2)
                return it.first;
        return -1;
    }
};