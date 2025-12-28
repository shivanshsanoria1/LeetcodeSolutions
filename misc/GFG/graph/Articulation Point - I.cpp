// https://www.geeksforgeeks.org/problems/articulation-point-1/1

class Solution {
private:
    void dfs(vector<int>adj[], vector<int>& visitTime, vector<int>& minTime, vector<bool>& isArtiPoint, int& t, int curr, int parent){
        t++;
        visitTime[curr] = t;
        minTime[curr] = t;
        
        int childs = 0;
        
        for(int nei: adj[curr]){
            if(nei == parent)
                continue;
            
            // visited neighbour
            if(visitTime[nei] != -1)
                minTime[curr] = min(minTime[curr], visitTime[nei]);
            // unvisited neighbour
            else{
                childs++;
                
                dfs(adj, visitTime, minTime, isArtiPoint, t, nei, curr);
                
                minTime[curr] = min(minTime[curr], minTime[nei]);
                
                if(minTime[nei] >= visitTime[curr] && parent != -1)
                    isArtiPoint[curr] = true;
            }
        }
        
        if(parent == -1 && childs > 1)
            isArtiPoint[curr] = true;
    }

public:
    // T.C.=O(V + E)
    vector<int> articulationPoints(int V, vector<int>adj[]) {
        // Code here
        
        vector<int> visitTime(V, -1);
        vector<int> minTime(V, -1);
        int t = 0;
        
        vector<bool> isArtiPoint(V, false);
        
        for(int i=0; i<V; i++)
            if(visitTime[i] == -1)
                dfs(adj, visitTime, minTime, isArtiPoint, t, i, -1);
        
        vector<int> points;

        for(int i=0; i<V; i++)
            if(isArtiPoint[i])
                points.push_back(i);
        
        if(points.size() == 0)
            points.push_back(-1);
        
        return points;
    }
};