class Solution {
private:
    #define INF INT_MAX

public:
    // T.C.=O(n), S.C.=O(1*n)
    int minimumSum(vector<int>& nums) {
        int n=nums.size();

        vector<int> minRight(n, INF);
        int postfixMin = nums[n-1];

        for(int i=n-2; i>=0; i--)
        {
            if(postfixMin < nums[i])
                minRight[i] = postfixMin;
            
            postfixMin = min(postfixMin, nums[i]);
        }
        
        int prefixMin = nums[0];
        int minSum = INF;
        
        for(int i=1; i<n; i++)
        {
            if(prefixMin < nums[i] && minRight[i] != INF)
                minSum = min(minSum, prefixMin + nums[i] + minRight[i]);
            
            prefixMin = min(prefixMin, nums[i]);
        }
        
        return minSum == INF ? -1 : minSum;
    }
};
/*
# minLeft[i]: min-element to the left of index i such that nums[left] < nums[i]
# minRight[i]: min-element to the right of index i such that nums[right] < nums[i]
# we don't really need to maintain 2 extra vectors, we can just maintain 1
*/