class Solution {
public:
    // T.C.=O(n), S.C.=O(1)
    bool canAliceWin(vector<int>& nums) {
        // sum of 1-digit and 2-digit nums respectively
        int sum1 = 0, sum2 = 0;
        for(int num: nums)
        {
            if(num < 10)
                sum1 += num;
            else
                sum2 += num;
        }

        return sum1 != sum2;
    }
};