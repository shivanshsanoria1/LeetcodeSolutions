class Solution {
private:
    typedef long long int lli;

public:
    // T.C.=O(n^2), S.C.=O(n)
    int countTrapezoids(vector<vector<int>>& points) {
        // step-1: y-coord -> freq
        unordered_map<int, int> mp;
        for(vector<int>& point: points)
            mp[point[1]]++;

        // step-2: num ways of choosing 2 points from n points is nC2
        vector<lli> ways;
        for(auto [y, n]: mp)
            ways.push_back((lli)n*(n-1)/2);

        // step-3: calcluate the final ans
        const int MOD = 1e9 + 7;
        int ans = 0;
        for(int i=0; i<ways.size()-1; i++)
            for(int j=i+1; j<ways.size(); j++)
                ans = (ans + (ways[i]*ways[j]) % MOD) % MOD;

        return ans;
    }
};

/*
# nC2 = n! / (2! * (n-2)!) = (n*(n-1))/2
# to form a horizontal trapezoid, 
  we need a pair of points with the same y-coord and 
  another pair of points with a other y-coord different from the 1st pair
*/