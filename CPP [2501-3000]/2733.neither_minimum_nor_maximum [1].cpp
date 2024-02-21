class Solution {
public:
    int findNonMinOrMax(vector<int>& nums) { // T.C.=O(n)
        int maxi = 0, mini = 101;
        for(int num: nums)
        {
            maxi = max(maxi, num);
            mini = min(mini, num);
        }
        for(int num: nums)
            if(num != maxi && num != mini)
                return num;
        return -1;
    }
};