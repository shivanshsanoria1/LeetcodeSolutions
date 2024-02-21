class Solution {
public:
    int findMaxK(vector<int>& nums) { // T.C.=O(n), S.C.=O(2*1001)
        vector<bool> pos(1001, false);
        vector<bool> neg(1001, false);
        for(int num: nums)
        {
            if(num > 0)
                pos[num] = true;
            else
                neg[-num] = true;
        }
        for(int i=1000; i>=1; i--)
            if(pos[i] && neg[i])
                return i;
        return -1;
    }
};