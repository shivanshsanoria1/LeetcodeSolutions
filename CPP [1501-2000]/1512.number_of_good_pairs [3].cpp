class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) { // T.C.=O(n), S.C.=O(n), single pass
        unordered_map<int, int> mp; // num -> freq
        int count = 0;
        for(int num: nums)
        {
            count += mp[num]; // add the prev freq of curr element to ans
            mp[num]++; // update the freq of curr element
        }
        return count;
    }
};