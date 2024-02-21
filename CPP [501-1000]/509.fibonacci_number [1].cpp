class Solution {
public:
    int fib(int n) {
        if(n==0)
            return 0;
        if(n==1)
            return 1;
        int f2=0, f1=1, f; //f is F(n) , f1 is F(n-1), f2 is F(n-2)
        for(int i=2; i<=n; i++)
        {
            f=f1+f2;
            f2=f1;
            f1=f;
        }
        return f;
    }
};