class Solution {
public:
    // T.C.=O(n), S.C.=O(1)
    int minOperations(vector<int>& nums) {
        int flips = 0;

        for(int num: nums)
        {
            int curr = flips % 2 == 0 ? num : !num;

            if(curr == 0)
                flips++;
        }
        
        return flips;
    }
};