class Solution {
public:
    int tribonacci(int n) {
        if(n==0)
            return 0;
        if(n==1 || n==2)
            return 1;
        int t3=0, t2=1, t1=1, t; //t is T(n), t1 is T(n-1), t2 is T(n-2), t3 is T(n-3)
        for(int i=3; i<=n; i++)
        {
            t=t1+t2+t3;
            t3=t2;
            t2=t1;
            t1=t;
        }
        return t;
    }
};