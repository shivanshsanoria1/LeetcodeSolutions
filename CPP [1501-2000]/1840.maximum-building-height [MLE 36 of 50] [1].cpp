class Solution {
public:
    // T.C.=O(n), S.C.=O(n)
    int maxBuilding(int n, vector<vector<int>>& restrictions) {
        vector<int> left(n, INT_MAX);
        vector<int> right(n, INT_MAX);

        // height of 0th building is always 0
        left[0] = 0;
        right[0] = 0;
        // max height of last building is (n-1) 
        // if there were no restrictions
        right[n-1] = n-1;

        for(vector<int>& restriction: restrictions){
            int i = restriction[0] - 1; // convert 1-indexed to 0-indexed
            int maxHeight = restriction[1];
            left[i] = maxHeight;
            right[i] = maxHeight;
        }
        
        // calculate the max possible height of each building 
        // starting from left and right directions
        for(int i=1; i<n; i++)
            left[i] = min(left[i], left[i-1] + 1);
        
        for(int i=n-2; i>0; i--)
            right[i] = min(right[i], right[i+1] + 1);
        
        // min(left[i], right[i]) is the actual max possible height for the ith building
        int maxHeight = 0;
        for(int i=0; i<n; i++)
            maxHeight = max(maxHeight, min(left[i], right[i]));

        return maxHeight;
    }
};