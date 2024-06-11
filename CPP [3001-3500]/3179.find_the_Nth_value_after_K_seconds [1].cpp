class Solution {
private:
    #define MOD int(1e9 + 7)

public:
    // T.C.=O(n*k), S.C.=O(n)
    int valueAfterKSeconds(int n, int k) {
        if(n == 1)
            return 1;
        if(n == 2)
            return k + 1;

        vector<int> nums(n, 1);
        while(k--)
            for(int i=1; i<n; i++)
                nums[i] = (nums[i] + nums[i-1]) % MOD;
                
        return nums[n-1];
    }
};