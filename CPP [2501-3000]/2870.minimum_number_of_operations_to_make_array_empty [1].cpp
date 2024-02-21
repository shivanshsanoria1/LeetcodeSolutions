class Solution {
public:
    // T.C.=O(n), S.C.=O(n)
    int minOperations(vector<int>& nums) {
        unordered_map<int, int> mp; // num -> freq
        for(int num: nums)
            mp[num]++;
        int ops = 0; // operations needed
        for(auto [num, freq]: mp)
        {
            if(freq == 1)
                return -1;

            if(freq % 3 == 0)
                ops += freq / 3;
            else
                ops += freq / 3 + 1;
        }
        return ops;
    }
    /*
    # impossible to delete an element with freq 1
    # freq % 3 == 0 : (freq / 3) type-3 operations required
    # freq % 3 == 1 : (freq / 3 - 1) type-3 and (2) type-2 operations required
    # freq % 3 == 2 : (freq / 3) type-3 and (1) type-2 operations required
    */
};