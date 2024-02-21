class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) { // T.C.=O(m*n), S.C.=O(m*n)
        int m=nums.size();
        vector<vector<bool>> visited(m);
        for(int i=0; i<m; i++)
            for(int j=0; j<nums[i].size(); j++)
                visited[i].push_back(false);

        vector<int> ans;
        queue<pair<int, int>> q;
        q.push({0, 0});
        while(!q.empty())
        {
            auto [x, y] = q.front();
            q.pop();
            ans.push_back(nums[x][y]);
            // down
            if(x+1 < nums.size() && y < nums[x+1].size() && !visited[x+1][y])
            {
                visited[x+1][y] = true;
                q.push({x+1, y});
            }
            // right
            if(y+1 < nums[x].size() && !visited[x][y+1])
            {
                visited[x][y+1] = true;
                q.push({x, y+1});
            }
        }
        return ans;
    }
};
// m: num of rows, n: max num of cols in any row
// BFS