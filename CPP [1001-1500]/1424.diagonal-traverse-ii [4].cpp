class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) { // T.C.=O(m*n), S.C.=O(sqrt(n))
        vector<int> ans;
        queue<pair<int, int>> q;
        q.push({0, 0});
        while(!q.empty())
        {
            auto [x, y] = q.front();
            q.pop();
            ans.push_back(nums[x][y]);
            // down
            if(y == 0 && x+1 < nums.size())
                q.push({x+1, y});
            // right
            if(y+1 < nums[x].size())
                q.push({x, y+1});
        }
        return ans;
    }
};
// m: num of rows, n: max num of cols in any row
// BFS