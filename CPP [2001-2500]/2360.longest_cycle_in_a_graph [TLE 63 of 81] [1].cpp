class Solution {
public:
    // T.C.=O(n^2), S.C.=O(n)
    int longestCycle(vector<int>& edges) {
        int n=edges.size();
        int maxCycleLen = 0;

        for(int i=0; i<n; i++)
        {
            int curr = i;
            int cycleLen = 0;
            vector<bool> visited(n, false);

            while(curr != -1 && !visited[curr])
            {
                visited[curr] = true;
                curr = edges[curr];
                cycleLen++;
            }

            if(curr != -1 && curr == i)
                maxCycleLen = max(maxCycleLen, cycleLen);
        }

        return maxCycleLen == 0 ? -1 : maxCycleLen;
    }
};