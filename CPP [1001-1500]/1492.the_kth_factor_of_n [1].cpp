class Solution {
public:
    int kthFactor(int n, int k) { // T.C.=O(sqrt(n))
        vector<int> factors; //for storing factors <= sqrt(n) in asc. order
        vector<int> factors2; //for storing factors > sqrt(n) in desc. order
        for(int i=1; i*i<=n; i++)
        {
            if(n % i == 0)
            {
                factors.push_back(i);
                if(n/i != i)
                    factors2.push_back(n/i);
            }
        }
        for(int i=factors2.size()-1; i>=0; i--)
            factors.push_back(factors2[i]);
        return k-1 < factors.size() ? factors[k-1] : -1;
    }
};
// Kth factor means factor[k-1] as k=1,2,3,... and i=0,1,2,...
