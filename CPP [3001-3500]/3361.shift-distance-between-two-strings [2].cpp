class Solution {
private:
    typedef long long int lli;

public:
	// T.C.=O(n + 26), S.C.=O(26)
    long long shiftDistance(string s, string t, vector<int>& nextCost, vector<int>& previousCost) {
    	// calculate the pefix-sum for forward cost
        vector<lli> prefixCostForward(26, 0);
        for(int i=0; i<26; i++)
            prefixCostForward[i] = nextCost[i];
        for(int i=1; i<26; i++)
            prefixCostForward[i] += prefixCostForward[i-1];
        
        // calculate the pefix-sum for backward cost
        vector<lli> prefixCostBackward(26, 0);
        for(int i=0; i<26; i++)
            prefixCostBackward[i] = previousCost[i];
        for(int i=1; i<26; i++)
            prefixCostBackward[i] += prefixCostBackward[i-1];
        
        lli minCost = 0;
        for(int i=0; i<s.length(); i++)
        {
            int start = s[i] - 'a';
            int end = t[i] - 'a';

            lli costForward = 0;
            lli costBackward = 0;

            if(start < end)
            {
                // sum of elements in index range [start, end-1] in prefixCostForward[]
                costForward = prefixCostForward[end-1] - (start-1 >= 0 ? prefixCostForward[start-1] : 0);
                // sum of elements in index range [0, start] + [end+1, 25] in prefixCostBackward[]
                costBackward = prefixCostBackward[start] + (prefixCostBackward[25] - prefixCostBackward[end]);
            }
            else if(start > end)
            {
                // sum of elements in index range [start, 25] + [0, end-1] in prefixCostForward[]
                costForward = (prefixCostForward[25] - prefixCostForward[start-1]) + (end-1 >= 0 ? prefixCostForward[end-1] : 0);
                // sum of elements in index range [end+1, start] in prefixCostBackward[]
                costBackward = prefixCostBackward[start] - prefixCostBackward[end];
            }

            minCost += min(costForward, costBackward);
        }

        return minCost;
    }
};

/*
in a prefix-sum array, sum of elements in index range [i, j] is:
	if i-1 >= 0: 
		prefixSum[j] - prefixSum[i-1]
	else: 
		prefixSum[j]
*/