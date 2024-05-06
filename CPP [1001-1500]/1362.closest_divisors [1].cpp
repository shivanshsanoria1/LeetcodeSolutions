class Solution {
private:
    // returns the 2 divisors of n whose product is n
    // and their diff is min
    vector<int> minDiffDivisors(int n){
        int d1 = 1, d2 = n;

        for(int i=floor(sqrt(n)); i>=1; i--)
            if(n % i == 0)
            {
                d1 = i;
                d2 = n/i;
                break;
            }
        
        return {d1, d2};
    }

public:
    // T.C.=O(sqrt(n)), S.C.=O(1)
    vector<int> closestDivisors(int num) {
        vector<int> divs1 = minDiffDivisors(num + 1);
        vector<int> divs2 = minDiffDivisors(num + 2);

        return divs1[1] - divs1[0] < divs2[1] - divs2[0] ? divs1 : divs2;
    }
};