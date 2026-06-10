class Solution {
private:
    typedef pair<int, int> PI;
    typedef pair<int, pair<int, int>> PII; // {diff, {i, j}}

public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m=heights.size(), n=heights[0].size();
        // visited grid of size m*n filled with false's
        vector<vector<bool>> visited(m, vector<bool>(n ,false));
        // min-heap
        priority_queue<PII, vector<PII>, greater<PII>> pq; 
        // up, down, left, right
        vector<PI> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        pq.push({0, {0, 0}});
        while(!pq.empty())
        {
            int currDiff = pq.top().first;
            auto [currX, currY] = pq.top().second;
            pq.pop();

            if(visited[currX][currY]) // already visited cell
                continue;
            visited[currX][currY] = true; // mark the curr cell as visited

            if(currX == m-1 && currY == n-1) // reached the last cell
                return currDiff;

            for(auto [dx, dy]: dirs)
            {
                int nextX = currX + dx;
                int nextY = currY + dy;

                if(nextX < 0 || nextX >= m || nextY < 0 || nextY >= n) // index out of bounds
                    continue;
                if(visited[nextX][nextY]) // already visited cell
                    continue;

                int nextDiff = abs(heights[currX][currY] - heights[nextX][nextY]); 
                pq.push({max(currDiff, nextDiff), {nextX, nextY}});
            }
        }
        return -1;
    }
};