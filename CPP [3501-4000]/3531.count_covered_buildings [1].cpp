class Solution {
public:
    // T.C.=O(n), S.C.=O(n)
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
        // stores the min and max y-coordinate for each x-coordinate
        vector<pair<int, int>> minmax_y(n+1, {n+1, 0});
        // stores the min and max x-coordinate for each y-coordinate
        vector<pair<int, int>> minmax_x(n+1, {n+1, 0});

        for(vector<int>& building: buildings)
        {
            int x = building[0], y = building[1];

            // update the min and max y-coordinate for curr x-coordinate
            minmax_y[x].first = min(minmax_y[x].first, y);
            minmax_y[x].second = max(minmax_y[x].second, y);

            // update the min and max x-coordinate for curr y-coordinate
            minmax_x[y].first = min(minmax_x[y].first, x);
            minmax_x[y].second = max(minmax_x[y].second, x);
        }

        int count = 0;
        for(vector<int>& building: buildings)
        {
            int x = building[0], y = building[1];
            
            // curr point is at the extreme end for its x-coordinate
            if(minmax_y[x].first == y || minmax_y[x].second == y)
                continue;
            // curr point is at the extreme end for its y-coordinate
            if(minmax_x[y].first == x || minmax_x[y].second == x)
                continue;

            count++;
        }

        return count;
    }
};