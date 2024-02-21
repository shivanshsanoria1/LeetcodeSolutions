class Solution {
public:
    bool checkPerfectNumber(int num) { //T.C.=O(sqrt(n))
        if(num==1) //1 is not a perfect num
            return false;
        int sum=0;
        for(int i=2; i*i<=num; i++)
            if(num%i==0)
            {
                sum+=i;
                if(i != num/i)
                    sum+=(num/i);
            }
        return sum+1==num ? true : false;
    }
};