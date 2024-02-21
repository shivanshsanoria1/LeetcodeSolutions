class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) { // T.C.=O(m*n), S.C.=O(m*n)
        vector<int> ans;
        queue<pair<int, int>> q;
        q.push({0, 0});
        unordered_set<string> visited;
        while(!q.empty())
        {
            auto [x, y] = q.front();
            q.pop();
            ans.push_back(nums[x][y]);
            string hash = "";
            // down
            if(x+1 < nums.size() && y < nums[x+1].size())
            {
                hash = to_string(x+1) + "#" + to_string(y);
                if(visited.find(hash) == visited.end()) // not found in set
                {
                    visited.insert(hash);
                    q.push({x+1, y});
                }
            }
            // right
            if(y+1 < nums[x].size())
            {
                hash = to_string(x) + "#" + to_string(y+1);
                if(visited.find(hash) == visited.end()) // not found in set
                {
                    visited.insert(hash);
                    q.push({x, y+1});
                }
            }
        }
        return ans;
    }
};
// m: num of rows, n: max num of cols in any row
// BFS