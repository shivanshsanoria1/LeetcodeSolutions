class Solution {
public:
    // T.C.=O(n)
    double myPow(double x, int n) {
        double pro = 1;

        if(n == 0)
            return pro;
        
        bool isNeg = n < 0 ? true : false;

        n = abs(n);

        while(n--)
            pro *= x;

        return isNeg ? 1/pro : pro;
    }
};