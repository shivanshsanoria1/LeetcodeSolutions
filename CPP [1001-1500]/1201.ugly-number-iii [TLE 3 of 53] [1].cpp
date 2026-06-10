class Solution {
public:
    int nthUglyNumber(int n, int a, int b, int c) {
        int i = 0;
        while(n > 0)
        {
            i++;
            if((i % a == 0) || (i % b == 0) || (i % c == 0))
                n--;
        }
        return i;
    }
};