class Solution {
private:
    typedef long long int lli;

    lli solve(vector<int>& a, vector<int>& b, int i, int j){
        if(i == 4 || j == b.size())
            return 0;

        lli res = LLONG_MIN;
        for(int k=j; k <= b.size() - 4 + i; k++)
            res = max(res, (lli)a[i]*b[k] + solve(a, b, i+1, k+1));

        return res;
    }

public:
    // Recursion
    long long maxScore(vector<int>& a, vector<int>& b) {
        return solve(a, b, 0, 0);
    }
};