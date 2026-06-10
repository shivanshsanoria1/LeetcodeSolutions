class Solution {
public:
    // T.C.=O(n), S.C.=O(100)
    bool isPossibleToSplit(vector<int>& nums) {
        vector<int> freq(101, 0);
        for(int num: nums)
        {
            freq[num]++;
            if(freq[num] > 2)
                return false;
        }
        return true;
    }
};