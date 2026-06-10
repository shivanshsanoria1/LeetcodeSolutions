class Solution {
public:
    // T.C.=O(n*log(n)), S.C.=O(n)
    // Greedy
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        int n=capacity.size();
        vector<int> freeSpace(n);
        for(int i=0; i<n; i++)
            freeSpace[i] = capacity[i] - rocks[i];
        
        sort(freeSpace.begin(), freeSpace.end());

        int fullBags = 0;
        for(int i=0; i<n; i++)
        {
            int rocksToFill = min(additionalRocks, freeSpace[i]);
            additionalRocks -= rocksToFill;
            freeSpace[i] -= rocksToFill;

            if(freeSpace[i] == 0)
                fullBags++;
        }

        return fullBags;
    }
};