class Solution {
public:
    int maxDistance(vector<int>& colors) { //T.C.=O(n^2)
        int n=colors.size(), max_dist=0;
        for(int i=0; i<n-1; i++)
            for(int j=n-1; j>i; j--)
                if(colors[i] != colors[j])
                {
                    max_dist= max(max_dist,j-i);
                    break;
                }
        return max_dist;
    }
};