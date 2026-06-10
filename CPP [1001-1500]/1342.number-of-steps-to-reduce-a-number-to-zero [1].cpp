class Solution {
public:
    int numberOfSteps(int num) {
        int c=0;
        while(num>0)
        {
            int rem=num%10;
            if(rem%2==0)
                num/=2;
            else
                num--;
            c++;
        }
        return c;
    }
};