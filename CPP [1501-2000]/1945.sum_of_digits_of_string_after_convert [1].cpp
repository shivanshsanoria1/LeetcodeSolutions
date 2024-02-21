class Solution {
public:
    int digitSum(int n) //finds sum of digits of num n
    {
        int sum=0;
        while(n>0)
        {
            sum+=n%10;
            n/=10;
        }
        return sum;
    }
    
    int getLucky(string s, int k) {
        int sum=0;
        for(int i=0; i<s.length(); i++)
        {
            int num=s[i]-'a'+1;
            num=digitSum(num);
            sum+=num;
        }
        k--; //1 k got consumed in calculating sum in the for loop
        while(k--)
        {
            if(sum<=9) //sum is now a single digit number
                return sum;
            sum= digitSum(sum);
        }
        return sum;
    }
};