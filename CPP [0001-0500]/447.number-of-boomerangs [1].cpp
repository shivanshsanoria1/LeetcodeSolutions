class Solution {
public:
    // T.C.=O(n^2), S.C.=O(n)
    int numberOfBoomerangs(vector<vector<int>>& points) {
        int count = 0;
        
        for(vector<int>& point: points)
        {
            int x1 = point[0], y1 = point[1];
            // dist between points (x1,y1) and (x2,y2) -> freq of such points (x2,y2)
            unordered_map<double, int> mp;

            for(vector<int>& point: points)
            {
                int x2 = point[0], y2 = point[1];
                double dist = sqrt((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2));
                mp[dist]++;
            }

            for(auto [dist, freq]: mp)
                count += freq * (freq - 1);
        }

        return count;
    }
};

/*
# for a fixed point (x1,y1) if we have 'f' points with a dist of 'd' from (x1,y1)
  then, the num of triplets for the point (x1,y1) is given by:
  fC2 = f*(f-1)/2
# but since the order of triplet matters, so each triplet is counted twice
# thus the triplets:
  {(x1,y1), (x2,y2), (x3,y3)} and {(x1,y1), (x3,y3), (x2,y2)}
  are considered different from each other
# therefore, the num of triplets for a fixed point (x1,y1)
  having 'f' points with a dist of 'd' from (x1,y1) is:
  f*(f-1)
*/