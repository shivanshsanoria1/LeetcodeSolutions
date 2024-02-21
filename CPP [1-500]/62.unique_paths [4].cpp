class Solution {
public:
    int uniquePaths(int m, int n) { //Math soln.
        int N=m-1+n-1; // answer is (m-1+n-1)C(m-1) or (m+n-2)!/[(m-1)!*(n-1)!]
        int R=m-1;
        long long int pro=1;
        for(int i=1; i<=R; i++)
            pro=pro*(N-R+i)/i;
        return pro;
    }
};