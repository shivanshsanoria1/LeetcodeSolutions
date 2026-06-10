class Solution {
private:
    #define INF INT_MAX

public:
    // T.C.=O(n), S.C.=O(2*n)
    int minimumSum(vector<int>& nums) {
        int n=nums.size();

        vector<int> minLeft(n, INF);
        vector<int> minRight(n, INF);

        int prefixMin = nums[0];
        for(int i=1; i<n; i++)
        {
            if(prefixMin < nums[i])
                minLeft[i] = prefixMin;
            
            prefixMin = min(prefixMin, nums[i]);
        }

        int postfixMin = nums[n-1];
        for(int i=n-2; i>=0; i--)
        {
            if(postfixMin < nums[i])
                minRight[i] = postfixMin;
            
            postfixMin = min(postfixMin, nums[i]);
        }
        
        int minSum = INF;

        for(int i=0; i<n; i++)
            if(minLeft[i] != INF && minRight[i] != INF)
                minSum = min(minSum, minLeft[i] + nums[i] + minRight[i]);
        
        return minSum == INF ? -1 : minSum;
    }
};
/*
# minLeft[i]: min-element to the left of index i such that nums[left] < nums[i]
# minRight[i]: min-element to the right of index i such that nums[right] < nums[i]
*/