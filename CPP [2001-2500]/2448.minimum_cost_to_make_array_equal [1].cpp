class Solution {
private:
    typedef long long int lli;

public:
    long long minCost(vector<int>& nums, vector<int>& cost) { // T.C.=O(n*logn), S.C.=O(n)
        // Step-1
        int n=nums.size();
        vector<pair<int, int>> vec(n); // {nums[i], cost[i]}
        for(int i=0; i<n; i++)
            vec[i] = {nums[i], cost[i]};
        sort(vec.begin(), vec.end()); // sort by nums[i]

        // Step-2
        vector<lli> preCosts(n); // prefix sum of cost[]
        preCosts[0] = vec[0].second;
        for(int i=1; i<n; i++)
            preCosts[i] = preCosts[i-1] + vec[i].second;
            
        // Step-3
        lli currCost = 0;
        // calculate curr cost assuming 0th index num as target
        for(int i=0; i<n; i++)
            currCost += (vec[i].first - vec[0].first) * (lli)vec[i].second;
        lli minCost = currCost;
        // calculate curr cost assuming ith index num as target
        for(int i=1; i<n; i++)
        {
            // find the diff in heights of curr and its prev num
            int diff = vec[i].first - vec[i-1].first;
            // increment the curr cost by: diff*(costs from 0 to i-1)
            currCost += (lli)diff * preCosts[i-1];
            // deccrement the curr cost by: diff*(costs from i to n-1)
            currCost -= (lli)diff * (preCosts[n-1] - preCosts[i-1]);
            minCost = min(minCost, currCost);
        }
        return minCost;
    }
};
/*
# Changing all the elements into one of the numbers already existing in the array, say target is optimal.
# assume the num at ith index is the target 
*/