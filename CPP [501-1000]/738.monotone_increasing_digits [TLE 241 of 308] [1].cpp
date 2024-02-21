class Solution {
public:
    bool isMonotoneIncreasing(int n)
    {
        int dig=10;
        while(n > 0)
        {
            if(n%10 > dig) //curr dig > prev dig
                return false;
            dig=n%10; //update dig
            n/=10;
        }
        return true;
    }
    
    int monotoneIncreasingDigits(int n) {
        for(int i=n; i>=0; i--)
            if(isMonotoneIncreasing(i)==true)
                return i;
        return false;
    }
};