class Solution {
public:
    // T.C.=O(n*logn), S.C.=O(1)
    int minimumLines(vector<vector<int>>& stockPrices) {
        int n=stockPrices.size();
        // no line can be formed with 1 point
        if(n == 1)
            return 0;

        // sort in increasing order of x-values (days)
        sort(stockPrices.begin(), stockPrices.end());

        int slopeChangeCount = 0;

        for(int i=2; i<n; i++)
        {
            int x2 = stockPrices[i-2][0], y2 = stockPrices[i-2][1];
            int x1 = stockPrices[i-1][0], y1 = stockPrices[i-1][1];
            int x0 = stockPrices[i][0], y0 = stockPrices[i][1];

            if((long long int)(y1-y2)*(x0-x1) != (long long int)(y0-y1)*(x1-x2))
                slopeChangeCount++;
        }

        return 1 + slopeChangeCount;
    }
};
/*
# 3 points (x2, y2), (x1, y1), (x0, y0) are non-collinear if:
  slope between (x2, y2) and (x1, y1) != slope between (x1, y1) and (x0, y0)
=> (y1-y2) / (x1-x2) != (y0-y1) / (x0-x1)
=> (y1-y2) * (x0-x1) != (y0-y1) * (x1-x2) 
*/