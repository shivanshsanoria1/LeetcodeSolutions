class Solution {
public:
    // T.C.=O(n), S.C.=O(1)
    int nearestDrone(vector<vector<int>>& drones, vector<int>& target) {
        const int n = drones.size();
        int minDist = INT_MAX;
        int idx = -1;
        for(int i=0; i<n; i++){
            const int x = drones[i][0];
            const int y = drones[i][1];
            const int r = drones[i][2];

            const int dist = abs(x - target[0]) + abs(y - target[1]);

            if(dist <= r && dist < minDist){
                minDist = dist;
                idx = i;
            }
        }

        return idx;
    }
};