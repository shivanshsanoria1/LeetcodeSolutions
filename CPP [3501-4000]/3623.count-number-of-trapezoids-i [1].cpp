class Solution {
private:
    typedef long long int lli;

public:
    // T.C.=O(n), S.C.=O(n)
    int countTrapezoids(vector<vector<int>>& points) {
        // step-1: y-coord -> freq
        unordered_map<int, int> mp;
        for(vector<int>& point: points)
            mp[point[1]]++;

        // step-2: num ways of choosing 2 points from n points is nC2
        vector<lli> ways;
        for(auto [y, n]: mp)
            ways.push_back((lli)n*(n-1)/2);
        
        // step-3: calulate prefix sum
        int w = ways.size();
        vector<lli> prefixSum(w, 0);
        prefixSum[0] = ways[0];
        for(int i=1; i<w; i++)
            prefixSum[i] = ways[i] + prefixSum[i-1];

        // step-4: calcluate the final ans
        const int MOD = 1e9 + 7;
        int ans = 0;
        for(int i=w-1; i>0; i--)
            ans = (ans + (ways[i]*prefixSum[i-1]) % MOD) % MOD;

        return ans;
    }
};

/*
# nC2 = n! / (2! * (n-2)!) = (n*(n-1))/2

# to form a horizontal trapezoid, 
  we need a pair of points with the same y-coord and 
  another pair of points with a other y-coord different from the 1st pair

# suppose the elements of ways[] are
  W0, W1, W2, ..., Wn-1
# the ans is calculated (using 2 loops) as 
   ans = 
   W0 * (W1 + W2 + ... + Wn-1)
 + w1 * (W2 + W3 + ... + Wn-1)
 + w2 * (W3 + W4 + ... + Wn-1)
 + ...
 + wn-2 * (Wn-1)

# this can be calculated using only 1 loop by using prefix-sum
  and iterating the array in reverse
# ans = 
   Wn-1 * (Wn-2 + ... + W1 + W0)
 + Wn-2 * (Wn-3 + ... + W1 + W0)
 + ...
 + W1 * (W0)

*/