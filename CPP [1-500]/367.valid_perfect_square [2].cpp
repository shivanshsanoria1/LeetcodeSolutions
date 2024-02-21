class Solution {
public:
    bool isPerfectSquare(int num) {
        int i=1;
        while(num>0) // trick: n^2 = sum of first n odd numbers
        {
            num=num-i;
            i=i+2;
        }
        if(num==0)
            return true;
        return false;
    }
};