class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int maxHeight=0, height=0;
        for(int i=0; i<gain.size(); i++)
        {
            height += gain[i];
            maxHeight = max(maxHeight, height);
        }
        return maxHeight;
    }
};