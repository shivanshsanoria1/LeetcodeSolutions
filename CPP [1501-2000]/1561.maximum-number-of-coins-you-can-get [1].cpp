class Solution {
public:
    // T.C.=O(n*log(n)), S.C.=O(1)
    // Greedy
    int maxCoins(vector<int>& piles) {
        sort(piles.begin(), piles.end());

        int sum = 0;
        for(int i=0, j=piles.size()-1; i<j; i++, j-=2)
            sum += piles[j-1];

        return sum;
    }
};

/*
it is optimal to take the 2 largest elements (say, B and C) 
and 1 smallest element (say, A) thus forming the sequence A,B,C
the median B is added to the answer until no more size 3 sequence is left

# similar: [3627. maximum-median-sum-of-subsequences-of-size-3]
*/