class Solution {
public:
    // T.C.=O(n), S.C.=O(n)
    int findMaxK(vector<int>& nums) { 
        // to store -ive nums
        unordered_set<int> neg; 

        for(int num: nums)
            if(num < 0)
                neg.insert(num);

        int maxPosNum = -1;

        for(int num: nums)
            // curr +ive num's corresponding -ive num is found in set
            if(num > 0 && neg.find(-num) != neg.end())
                maxPosNum = max(maxPosNum, num);

        return maxPosNum;
    }
};