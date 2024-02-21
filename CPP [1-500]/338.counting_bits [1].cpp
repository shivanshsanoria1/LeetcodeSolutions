class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans(n+1);
        ans[0] = 0;
        for(int i=0; i<=n; i++)
            ans[i] = (i % 2 == 0) ? ans[i/2] : ans[i/2] + 1;
        return ans;
    }
};
/*
# if i is even-
  number i has same no. of 1's (in binary) as the number i/2, 
  since left shifting i/2 by 1 gives i (without affecting no. of 1's)
# (i+1) is odd-
  number (i+1) has same no. of 1's (in binary) as the number (i/2+1), 
  since left shifting i/2 by 1 gives i (without affecting no. of 1's)
*/