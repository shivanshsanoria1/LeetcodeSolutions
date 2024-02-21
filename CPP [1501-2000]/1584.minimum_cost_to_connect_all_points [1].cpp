class Solution {
private:
    typedef pair<int, int> PI; // {dist, vertex}

public:
    int minCostConnectPoints(vector<vector<int>>& points) { // Prim's algo. for MST
        int n = points.size();
        vector<bool> visited(n, false);
        priority_queue<PI, vector<PI>, greater<PI>> pq; // min-heap
        pq.push({0, 0}); // push 0 distance and the 0th vertex in heap
        int minTotalDist = 0;
        int visitedCount = 0;
        while(visitedCount < n)
        {
            int currDist = pq.top().first;
            int currVert = pq.top().second;
            pq.pop();
            int x1 = points[currVert][0], y1 = points[currVert][1]; // (x1,y1)
            if(visited[currVert]) // curr vertex is already visited
                continue;
            visited[currVert] = true; // mark the curr vertex as visited
            visitedCount++; // increment the visited count
            minTotalDist += currDist; // add the curr distance to ans
            for(int i=0; i<n; i++) // iterate through the neighbours of curr vertex
            {
                if(visited[i]) // skip the already visited neighbours
                    continue;
                int x2 = points[i][0], y2 = points[i][1]; // (x2,y2)
                int dist = abs(x2 - x1) + abs(y2 - y1); // dist between (x1,y1) and (x2,y2)
                // push the dist between curr vertex and its neighbour and the neighbour in heap
                pq.push({dist, i}); 
            }
        }
        return minTotalDist;
    }
};