class Solution {
public:
    typedef pair<int, int> PI;

    long long findScore(vector<int>& nums) { // T.C.=O(n*logn), S.C.=O(n)
        int n = nums.size();
        priority_queue<PI, vector<PI>, greater<PI>> pq; // min-heap
        vector<bool> visited(n, false); // initially all indexes are unvisited
        for(int i=0; i<n; i++)
            pq.push({nums[i], i});
        long long int ans=0;
        while(!pq.empty())
        {
            auto curr = pq.top();
            pq.pop();
            int idx = curr.second;
            if(visited[idx] == false) // curr index is unvisited
            {
                ans += curr.first;
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