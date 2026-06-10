class Solution {
public:
    // T.C.=O(n), S.C.=O(1)
    int maximumPossibleSize(vector<int>& nums) {
        int prev = -1;
        int count = 0;

        for(int num: nums)
            if(prev <= num)
            {
                prev = num;
                count++;
            }

        return count;
    }
};