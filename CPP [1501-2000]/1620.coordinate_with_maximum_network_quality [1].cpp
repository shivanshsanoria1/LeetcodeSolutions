class Solution {
private:
    // returns the total network quality of all the towers 
    // reachable from the point (cx, cy)
    int findNetWorkQuality(vector<vector<int>>& towers, int radius, int cx, int cy){
        int quality = 0;
        for(vector<int>& tower: towers)
        {
            int x = tower[0], y = tower[1];
            int q = tower[2];

            double dist = sqrt((x - cx)*(x - cx) + (y - cy)*(y - cy));
            if(dist <= radius)
                quality += q / (1 + dist);
        }

        return quality;
    }

public:
    // T.C.=O(50*50*n), S.C.=O(1)
    vector<int> bestCoordinate(vector<vector<int>>& towers, int radius) {
        int maxNetworkQuality = 0;
        vector<int> ans(2, 0);

        for(int x=0; x<=50; x++)
            for(int y=0; y<=50; y++)
            {
                int networkQuality = findNetWorkQuality(towers, radius, x, y);
                if(networkQuality > maxNetworkQuality)
                {
                    maxNetworkQuality = networkQuality;
                    ans[0] = x;
                    ans[1] = y;
                }
            }

        return ans;
    }
};