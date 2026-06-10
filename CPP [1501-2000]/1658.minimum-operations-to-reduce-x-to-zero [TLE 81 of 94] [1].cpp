class Solution {
public:
    int minOperations(vector<int>& nums, int x) { // T.C.=O(n^2), S.C.=O(n)
        int n=nums.size();
        if(nums[0] == x || nums[n-1] == x)
            return 1;

        vector<int> preSum(n, 0); // prefix-sum
        vector<int> postSum(n, 0); // postfix-sum
        int minOp = INT_MAX;

        // calculate prefix-sum
        preSum[0] = nums[0];
        for(int i=1; i<n; i++)
        {
            preSum[i] = preSum[i-1] + nums[i];
            if(preSum[i] == x)
                minOp = min(minOp, i+1);
        }

        // calculate postfix-sum
        postSum[n-1] = nums[n-1];
        for(int i=n-2; i>=0; i--)
        {
            postSum[i] = postSum[i+1] + nums[i];
            if(postSum[i] == x)
                minOp = min(minOp, n-i);
        }
        
        // find a prefix-sum and postfix-sum that sum upto x
        for(int i=0; i<n; i++)
            for(int j=n-1; j>=0; j--)
            {
                if(i >= j)
                    break;
                if(preSum[i] + postSum[j] == x)
                {
                    minOp = min(minOp, n-j+i+1);
                    break;
                }
            }

        return minOp == INT_MAX ? -1 : minOp;
    }
};