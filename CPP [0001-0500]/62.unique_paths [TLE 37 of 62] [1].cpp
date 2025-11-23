class Solution {
public:
    int m1,n1;
    int uniquePaths(int m, int n) {
        m1=m;
        n1=n;
        return solve(0,0);
    }
    
    int solve(int a, int b)
    {
        if(a>=m1 || b>=n1) // Down or Right move leads to out of bounds
            return 0;
        if(a==m1-1 && b==n1-1) // reached the destination
            return 1;
        return solve(a+1,b) + solve(a,b+1);
    }
};