class Solution {
private:
    typedef long long int lli;

    lli solve(vector<int>& a, vector<int>& b, int i, int j){
        int n=b.size();
        if(i == 4 || j == n)
            return 0;
        
        lli include = (lli)a[i]*b[j] + solve(a, b, i+1, j+1);
        lli exclude = j-i == n-4 ? LLONG_MIN : solve(a, b, i, j+1);

        return max(include, exclude);
    }

public:
    // Recursion
    long long maxScore(vector<int>& a, vector<int>& b) {
        return solve(a, b, 0, 0);
    }
};