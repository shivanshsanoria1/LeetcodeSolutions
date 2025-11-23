class Solution {
public:
    int nthMagicalNumber(int n, int a, int b) {
        int nth = 0;
        for(int num=2; n>0; num++)
            if(num % a == 0 || num % b == 0)
            {
                nth = num;
                n--;
            }
        return nth;
    }
};