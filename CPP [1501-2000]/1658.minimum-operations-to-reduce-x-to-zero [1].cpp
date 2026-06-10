class Solution {
public:
    int minOperations(vector<int>& nums, int x) { // T.C.=O(n), S.C.=O(n)
        int n=nums.size();
        if(nums[0] == x || nums[n-1] == x)
            return 1;

        vector<int> preSum(n, 0); // prefix-sum
        vector<int> postSum(n, 0); // postfix-sum
        int minOp = INT_MAX; // min. operations to sum to x

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

        // add postfix-sums and their index to map
        unordered_map<int, int> mp; // num -> index
        for(int i=0; i<n; i++)
            mp[postSum[i]] = i;
        
        // iterate through prefix-sums and find the corresponding 
        // postfix-sum (if exist) 
        for(int i=0; i<n; i++)
            if(mp.find(x - preSum[i]) != mp.end())
            {
                int j = mp[x - preSum[i]];
                if(i < j)
                    minOp = min(minOp, n-j+i+1);
            }

        return minOp == INT_MAX ? -1 : minOp;
    }
};