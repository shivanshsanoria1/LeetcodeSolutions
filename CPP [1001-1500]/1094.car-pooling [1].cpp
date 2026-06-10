class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<int> cap(1001, 0);
        for(auto& trip: trips)
            for(int i=trip[1]; i<trip[2]; i++)
            {
                cap[i] += trip[0];
                if(cap[i] > capacity)
                    return false;
            }
        return true;
    }
};