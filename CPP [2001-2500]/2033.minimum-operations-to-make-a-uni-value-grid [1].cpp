class Solution {
public:
    // T.C.=O(m*n*log(m*n)), S.C.=O(m*n)
    // Greedy
    int minOperations(vector<vector<int>>& grid, int x) {
        int m=grid.size(), n=grid[0].size();
        vector<int> nums;
        for(int i=0; i<m; i++)
            for(int j=0; j<n; j++)
                nums.push_back(grid[i][j]);
        
        sort(nums.begin(), nums.end());

        for(int i=1; i<m*n; i++)
            if((nums[i] - nums[i-1]) % x != 0)
                return -1;
        
        int median = nums[m*n/2];
        int ops = 0;
        for(int num: nums)
            ops += abs(median - num)/x;
        
        return ops;
    }
};
/*
# the final value must be one of the 
  values already present in the grid
# to convert a num 'a' into another num 'b': 
  a +- k*x = b; where, k = 1,2,3,...
# since k is a natural num, 
  |a-b| must be a divisible by x
  mathematically: 
  abs(a-b) % x == 0
# if 'a' can be converted into 'b' and 
  'b' can be converted into 'c' then
  'a' can be converted into 'c'
  mathematically:
  a +- k1*x = b [1] and b +- k2*x = c [2], then
  a +- k1*x = c -+ k2*x
  a +- (k1 + k2)*x = c
  a +- k3*x = c [3]
  thus if equations [1] and [2] are true then [3] is also true
# the num of operations required to convert 'a' into 'b' is:
  abs(a-b)/x
# to minimize the num of operations every num
  must be converted into the MEDIAN value
*/