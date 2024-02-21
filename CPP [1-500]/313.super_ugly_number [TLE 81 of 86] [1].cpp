class Solution {
public:
    bool isUgly(vector<int>& primes, int n)
    {
        for(int i=0; i<primes.size(); i++)
            while(n%primes[i]==0)
                n=n/primes[i];
        if(n==1)
            return true;
        return false;
    }
    
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        int x=1; //start with num 1
        while(n>0)
        {
            if(isUgly(primes,x)==true) //if ugly num is found, decrement the count
                n--;
            x++;
        }
        return x-1;
    }
};