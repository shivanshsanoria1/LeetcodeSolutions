class Solution {
public:
    // T.C.=O(n), S.C.=O(1)
    int minimumOperations(vector<int>& nums) {
        int count = 0;
        for(int num: nums)
            if(num % 3 != 0)
                count++;
                
        return count;
    }
};