class Solution {
public:
    // T.C.=O(n), S.C.=O(n)
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();

        vector<int> prefixPros(n, 0);
        int prefixPro = 1;
        for(int i=0; i<n && prefixPro != 0; i++)
        {
            prefixPros[i] = prefixPro;
            prefixPro *= nums[i];
        }

        vector<int> suffixPros(n, 0);
        int suffixPro = 1;
        for(int i=n-1; i>=0 && suffixPro != 0; i--)
        {
            suffixPros[i] = suffixPro;
            suffixPro *= nums[i];
        }

        vector<int> ans(n, 0);
        for(int i=0; i<n; i++)
            ans[i] = prefixPros[i] * suffixPros[i];
        
        return ans;
    }
};