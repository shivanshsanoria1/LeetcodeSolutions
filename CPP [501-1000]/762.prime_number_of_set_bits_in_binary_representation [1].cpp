class Solution {
public:
    int countSetBits(int num)
    {
        int n=num, c=0;
        while(n>0)
        {
            c+=n&1;
            n=n>>1;
        }
        return c;
    }
    
    int countPrimeSetBits(int left, int right) {
        int c=0;
        vector<int> primes={2,3,5,7,11,13,17,19,23,29,31}; //max num of bits in int is 31
        for(int i=left; i<=right; i++)
            for(int j=0; j<11; j++)
                if(countSetBits(i)==primes[j])
                {
                    c++;
                    break;
                }
        return c;
    }
};