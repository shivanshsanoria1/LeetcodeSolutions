class Solution {
public:
    // T.C.=(b + c*k), S.C.=O(b)
    // b: size of obstacles[], c: size of commands[], k: max val in commands[] 
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        unordered_set<string> obs;
        for(vector<int>& obstacle: obstacles)
        {
            int x = obstacle[0], y = obstacle[1];
            string hash = to_string(x) + "#" + to_string(y);
            obs.insert(hash);
        }

        // curr x and y coordinates
        int x = 0, y = 0;
        // 0: North, 1: East, 2: South, 3: West
        int dirIdx = 0;
        vector<pair<int, int>> dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int maxDist2 = 0;

        for(int command: commands)
        {
            if(command == -1) // turn Right
            {
                dirIdx = (dirIdx + 1) % 4;
                continue;
            }
            if(command == -2) // turn Left
            {
                dirIdx = (dirIdx - 1 + 4) % 4;
                continue;
            }

            while(command--)
            {
                auto [dx, dy] = dirs[dirIdx];
                int nextX = x + dx;
                int nextY = y + dy;

                string hash = to_string(nextX) + "#" + to_string(nextY);
                // obstacle found
                if(obs.find(hash) != obs.end())
                    break;
                
                x = nextX;
                y = nextY;
            }

            maxDist2 = max(maxDist2, x*x + y*y);
        }

        return maxDist2;
    }
};