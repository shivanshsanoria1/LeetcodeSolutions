class Solution {
public:
    int findMaxK(vector<int>& nums) { // T.C.=O(n), S.C.=O(n)
        unordered_set<int> neg; // to store -ive nums
        for(int num: nums)
            if(num < 0)
                neg.insert(num);
        int ans = -1;
        for(int num: nums)
            // curr +ive num's corresponding -ive num is found in set
            if(num > 0 && neg.find(-num) != neg.end())
                ans = max(ans, num);
        return ans;
    }
};