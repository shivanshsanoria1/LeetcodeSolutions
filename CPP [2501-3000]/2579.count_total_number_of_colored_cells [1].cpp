class Solution {
public:
    long long coloredCells(int n) {
        long long int ans = 1;
        for(int i=2; i<=n; i++)
            ans += 4*(i-1);
        return ans;
    }
};
/*
# n = 1,2,3,4,...
# ans = 1, 5, 13, 25, ...
# diff = 0, 4, 8, 12, ...
*/