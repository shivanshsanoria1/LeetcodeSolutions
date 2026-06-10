class Solution {
public:
    // T.C.=O(n^2), S.C.=O(1)
    int findMaximumXOR(vector<int>& nums) {
        int n=nums.size();
        int x = 0;
        
        for(int i=0; i<n; i++)
            for(int j=i; j<n; j++)
                x = max(x, nums[i] ^ nums[j]);
        
        return x;
    }
};