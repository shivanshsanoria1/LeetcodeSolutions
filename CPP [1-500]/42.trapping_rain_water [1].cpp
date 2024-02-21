class Solution {
public:
    int trap(vector<int>& height) { //T.C=O(n) , S.C.=O(n) , using 2 extra vectors
        int n=height.size();
        if(n < 3) // atleast 3 bars are required to trap water
            return 0;
        vector<int> max_left(n); // keeps track of max bar to the left of current bar
        vector<int> max_right(n); // keeps track of max bar to the right of current bar
        int ml=height[0]; // max bar to the left
        int mr=height[n-1]; // max bar to the right

        max_left[0]=0; // first element has no max left
        for(int i=1; i<n; i++)
        {
            max_left[i] = ml;
            if(height[i] > ml) // if height of current bar > max height of bar to the left
                ml = height[i]; // then update the value of ml
        }

        max_right[n-1]=0; // last element has no max right
        for(int i=n-2; i>=0; i--)
        {
            max_right[i] = mr;
            if(height[i] > mr) // if height of current bar > max height of bar to the right
                mr = height[i]; // then update the value of mr
        }

        int water_level, water_sum=0;
        for(int i=1; i<n-1; i++)
        {
            water_level = min(max_left[i],max_right[i]);
            if(water_level > height[i]) // height of current bar must be < both max bar to the left and to the right
                water_sum += (water_level-height[i]);
        }
        return water_sum;
    }
};