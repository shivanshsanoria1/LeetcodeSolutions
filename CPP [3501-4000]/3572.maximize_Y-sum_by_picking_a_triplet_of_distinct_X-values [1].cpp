class Solution {
private:
    typedef pair<int, int> PII;

public:
    // T.C.=O(n*log(n)), S.C.=O(n)
    int maxSumDistinctTriplet(vector<int>& x, vector<int>& y) {
        unordered_set<int> sx;
        for(int num: x)
        {
            sx.insert(num);
            if(sx.size() == 3)
                break;
        }
        
        // x[] must have atleast 3 distinct elements
        if(sx.size() < 3)
            return -1;

        // clear the set for further use
        sx.clear();

        int n = x.size();
        vector<PII> nums;
        for(int i=0; i<n; i++)
            nums.push_back({y[i], x[i]});

        // sort in decreasing order of y-val
        sort(nums.begin(), nums.end(), greater<PII>());

        int maxSum = 0;
        for(auto [numY, numX]: nums)
        {
            // x already present in set
            if(sx.find(numX) != sx.end())
                continue;
            
            maxSum += numY;

            sx.insert(numX);
            if(sx.size() == 3)
                break;
        }

        return maxSum;
    }
};