class Solution {
public:
    int arithmeticTriplets(vector<int>& nums, int diff) { // T.C.=O(n), S.C.=O(n)
        unordered_set<int> s(nums.begin(), nums.end());
        int count = 0;
        for(int num: nums)
            if(s.find(num + diff) != s.end() && s.find(num + 2*diff) != s.end())
                count++;
        return count;
    }
};