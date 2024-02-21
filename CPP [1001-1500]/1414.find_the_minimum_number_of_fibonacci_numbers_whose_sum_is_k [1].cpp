class Solution {
public:
    int findMinFibonacciNumbers(int k) {
        vector<int> fib; //to store fibonacci nums <= k
        fib.push_back(0);
        fib.push_back(1);
        int i=2, f=1;
        while(1)
        {
            f= fib[i-1] + fib[i-2];
            if(f > k)
                break;
            fib.push_back(f);
            i++;
        }
        int c=0;
        for(int i=fib.size()-1; i>=2; i--)
            while(k >= fib[i])
            {
                k -= fib[i];
                c++;
            }
        return c;
    }
};