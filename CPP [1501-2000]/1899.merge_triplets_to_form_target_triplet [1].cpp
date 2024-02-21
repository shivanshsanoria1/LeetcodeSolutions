class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        bool x=false, y=false, z=false;
        for(auto& trip: triplets)
        {
            if(trip[0] > target[0] || trip[1] > target[1] || trip[2] > target[2])
                continue;
            if(trip[0] == target[0])
                x = true;
            if(trip[1] == target[1])
                y = true;
            if(trip[2] == target[2])
                z = true;
            if(x && y && z)
                return true;
        }
        return false;
    }
};