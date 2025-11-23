class Solution {
public:
    int mySqrt(int x) {
        if(x==0)
            return 0;
        int p=1;
        while(p<=x/p)
            p++;
        return p-1;
    }
};