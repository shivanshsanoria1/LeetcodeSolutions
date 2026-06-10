class Solution {
public:
    int climbStairs(int n) { // T.C.=O(n), S.C.=O(1)
        if(n<=2)
            return n;
        int s2=1, s1=2, s; // s2 is S(n-2), s1 is S(n-1), s is S(n)
        for(int i=3; i<=n; i++)
        {
            s= s1 + s2; // find s
            s2= s1; // update s2 to s1
            s1= s; // update s1 to s
        }
        return s;
    }
};