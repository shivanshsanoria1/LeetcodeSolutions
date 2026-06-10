class Solution {
public:
    // T.C.=O(n + 100), S.C.=O(100)
    int minOperations(vector<int>& nums, int k) {
        if(*min_element(nums.begin(), nums.end()) < k)
            return -1;
        
        vector<bool> isFound(101, false);
        for(int num: nums)
            isFound[num] = true;

        int cnt = count(isFound.begin(), isFound.end(), true);

        return isFound[k] ? cnt - 1 : cnt;
    }
};