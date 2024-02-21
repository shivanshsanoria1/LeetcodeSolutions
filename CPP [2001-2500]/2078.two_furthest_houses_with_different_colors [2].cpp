class Solution {
public:
    int maxDistance(vector<int>& colors) { //T.C.=O(n), the max distance will always include either first or the last house
        int n=colors.size(), max_dist1, max_dist2;
        for(int i=n-1; i>0; i--) //find max distance from 0th house
            if(colors[i] != colors[0])
            {
                max_dist1=i;
                break;
            }
        for(int i=0; i<n-1; i++) //find max distance from last house
            if(colors[i] != colors[n-1])
            {
                max_dist2=n-1-i;
                break;
            }
        return max(max_dist1,max_dist2);
    }
};