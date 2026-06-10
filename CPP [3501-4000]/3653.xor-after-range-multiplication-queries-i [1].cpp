class Solution {
public:
    // T.C.=O(n*q), S.C.=O(1)
    // n: size of nums[], q: size of queries[]
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        const int MOD = int(1e9 + 7);
        for(vector<int>& query: queries){
            int l = query[0], r = query[1];
            int k = query[2];
            int v = query[3];

            for(int i=l; i<=r; i += k)
                nums[i] = (nums[i] * v) % MOD;
        }

        int x = 0;
        for(int num: nums)
            x ^= num;
        
        return x;
    }
};