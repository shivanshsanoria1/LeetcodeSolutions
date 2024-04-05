class Solution {
public:
    // T.C.=O(n^2), S.C.=O(n)
    vector<int> countVisitedNodes(vector<int>& edges) {
        int n=edges.size();
        
        vector<int> ans(n, 0); 

        for(int i=0; i<n; i++)
        {
            vector<bool> visited(n, false);
            int curr = i;
            int count = 0;

            while(!visited[curr])
            {
                visited[curr] = true;
                curr = edges[curr];
                count++;
            }

            ans[i] = count;
        }

        return ans;
    }
};