class Solution {
public:
    bool isHappy(int n) { // similar to FLOYD'S CYCLE DETECTION algo.
        int slow=n, fast=n;
        do{
            slow=digitSum(slow);
            fast=digitSum(fast);
            fast=digitSum(fast);
            if(fast==1) return true;
        }while(slow!=fast);
        return false;
    }
    
    int digitSum(int x) // gives sum of squares of digits
    {
        int digit,sum=0;
        while(x>0)
        {
            digit=x%10;
            x=x/10;
            sum = sum + (digit*digit);
        }
        return sum;
    }
};