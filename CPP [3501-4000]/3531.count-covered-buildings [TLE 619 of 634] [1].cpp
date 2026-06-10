class Solution {
public:
    // T.C.=O(n^2), S.C.=O(1)
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
        int count = 0;
        for(vector<int>& building: buildings)
        {
            int x0 = building[0], y0 = building[1];
            bool up = false, down = false, left = false, right = false;
            
            for(vector<int>& building: buildings)
            {
                int x = building[0], y = building[1];

                if(x == x0 && y > y0)
                    up = true;
                else if(x == x0 && y < y0)
                    down = true;
                else if(y == y0 && x < x0)
                    left = true;
                else if(y == y0 && x > x0)
                    right = true;
                
                if(up && down && left && right)
                {
                    count++;
                    break;
                }
            }
        }

        return count;
    }
};