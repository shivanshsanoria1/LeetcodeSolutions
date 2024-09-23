class Solution {
private:
    int solve(int curr, int n, int& k){
        if(curr > n)
            return 0;
        
        if(curr > 0)
            k--;
        
        if(k == 0)
            return curr;
        
        for(int i = curr == 0 ? 1 : 0; i <= 9; i++)
        {
            int res = solve(curr * 10 + i, n, k);

            if(res > 0)
                return res;
        }
        
        return 0;
    }

public:
    // T.C.=O(k), S.C.=O(log10(n))
    int findKthNumber(int n, int k) {
        int k2 = k;
        return solve(0, n, k2);
    }
};