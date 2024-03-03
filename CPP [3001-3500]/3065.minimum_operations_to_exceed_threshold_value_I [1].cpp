class Solution {
public:
    // T.C.=O(n), S.C.=O(1)
    int minOperations(vector<int>& nums, int k) {
        int count = 0;
        for(int num: nums)
            if(num < k)
                count++;
        return count;
    }
};