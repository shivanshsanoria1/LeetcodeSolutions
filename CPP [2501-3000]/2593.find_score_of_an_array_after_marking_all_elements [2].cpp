class Solution {
public:
    long long findScore(vector<int>& nums) { // T.C.=O(n*logn), S.C.=O(n)
        int n = nums.size();
        set<pair<int, int>> s;
        vector<bool> visited(n, false); // initially all indexes are unvisited
        for(int i=0; i<n; i++)
            s.insert({nums[i], i});
        long long int ans=0;
        for(auto it: s)
        {
            int idx = it.second;
            if(visited[idx] == false) // curr index is unvisited
            {
                ans += it.first;
                visited[idx] = true; // mark the curr index as visited
                if(idx - 1 >= 0) // mark the left index of curr index as visited
                    visited[idx - 1] = true;
                if(idx + 1 < n) // mark the right index of curr index as visited
                    visited[idx + 1] = true;
            }
        }
        return ans;
    }
};