class Solution {
public:
    // T.C.=O(n), S.C.=O(1)
    int evenNumberBitwiseORs(vector<int>& nums) {
        int ans = 0;
        for(int num: nums)
            if(num % 2 == 0)
                ans |= num;
        
        return ans;
    }
};