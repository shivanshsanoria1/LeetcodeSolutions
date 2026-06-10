class Solution {
public:
    long long minCuttingCost(int n, int m, int k) {
        long long int cost = 0;

        if(n > k)
            cost += (long long int)k*(n-k);
        if(m > k)
            cost += (long long int)k*(m-k);
        
        return cost;
    }
};