class Solution {
public:
    int gcd(int a, int b) //returns gcd of a and b
    {
        while(a != b)
        {
            if(a > b)
                a -= b;
            else
                b -= a;
        }
        return a;
    }
    
    int factors(int n) //returns num of factors of n
    {
        int count=0;
        for(int i=1; i*i<=n; i++)
            if(n % i == 0)
            {
                count++; // i is a factor
                if(i != n/i)
                    count++; // n/i is also a factor 
            }
        return count;
    }
    
    int commonFactors(int a, int b) {
        int g= gcd(a,b);
        return factors(g);
    }
};