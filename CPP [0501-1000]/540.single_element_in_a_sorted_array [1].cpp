class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) { // T.C.=O(n), S.C.=O(n)
        int ans = 0;
        unordered_map<int, int> mp; // num -> freq
        for(int num: nums)
            mp[num]++;
        for(auto it: mp)
            if(it.second == 1)
                return it.first;
        return -1;
    }
};