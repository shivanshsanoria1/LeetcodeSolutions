class Solution {
public:
    // T.C.=O(n), S.C.=O(1)
    vector<int> bestTower(vector<vector<int>>& towers, vector<int>& center, int radius) {
        int x0 = center[0], y0 = center[1];
        int maxQ = -1;
        vector<int> ans(2, -1);

        for(vector<int>& tower: towers){
            int x = tower[0], y = tower[1];
            int q = tower[2];

            if(abs(x - x0) + abs(y - y0) > radius)
                continue;

            if(q > maxQ){
                maxQ = q;
                ans[0] = x;
                ans[1] = y;
            }else if(q == maxQ && (x < ans[0] || (x == ans[0] && y < ans[1]))){
                ans[0] = x;
                ans[1] = y;
            }
        }

        return ans;
    }
};