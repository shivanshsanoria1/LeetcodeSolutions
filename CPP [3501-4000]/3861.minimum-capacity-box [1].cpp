class Solution {
public:
    // T.C.=O(n), S.C.=O(1)
    int minimumIndex(vector<int>& capacity, int itemSize) {
        int closestCap = 101;
        int idx = -1;
        for(int i=0; i<capacity.size(); i++)
            if(capacity[i] >= itemSize && capacity[i] < closestCap){
                closestCap = capacity[i];
                idx = i;
            }
        
        return idx;
    }
};