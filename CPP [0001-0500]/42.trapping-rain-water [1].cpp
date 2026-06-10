class Solution {
public:
    // T.C=O(n), S.C.=O(n)
    // using 2 extra vectors
    int trap(vector<int>& height) { 
        int n=height.size();
        // atleast 3 bars are required to trap water
        if(n < 3) 
            return 0;

        // keeps track of max bar to the left of current bar 
        vector<int> maxLeft(n); 
        // max bar to the left
        int ml = height[0]; 
        // first element has no max left
        maxLeft[0] = 0; 

        for(int i=1; i<n; i++)
        {
            maxLeft[i] = ml;
            ml = max(ml, height[i]);
        }

        // keeps track of max bar to the right of current bar
        vector<int> maxRight(n); 
        // max bar to the right 
        int mr = height[n-1];
        // last element has no max right
        maxRight[n-1] = 0; 

        for(int i=n-2; i>=0; i--)
        {
            maxRight[i] = mr;
            mr = max(mr, height[i]);
        }

        int waterLevel = 0;
        int waterSum = 0;
        
        for(int i=1; i<n-1; i++)
        {
            waterLevel = min(maxLeft[i], maxRight[i]);
            // height of current bar must be < both max bar to the left and to the right
            if(waterLevel > height[i]) 
                waterSum += (waterLevel - height[i]);
        }

        return waterSum;
    }
};