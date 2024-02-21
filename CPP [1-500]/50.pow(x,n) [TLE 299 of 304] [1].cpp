class Solution {
public:
    double myPow(double x, int n) {
        double pro=1;
        if(n==0)
            return pro;
        else if(n>0)
        {
            while(n>0)
            {
                pro=pro*x;
                n--;
            }
            return pro;
        }
        n=-n;
        while(n>0)
        {
            pro=pro*x;
            n--;
        }
        return 1/pro;
    }
};