class Solution {
public:
    // T.C.=O(n), S.C.=O(1)
    // 2-pointer
    int trap(vector<int>& height) {
        int n=height.size();
        // atleast 3 bars are required to trap water
        if(n < 3) 
            return 0;

        // initially first element is max left and last element is max right
        int maxLeft = height[0]; 
        int maxRight = height[n-1];
        // initially left and right pointers are at 2nd and 2nd last position respectively 
        int left = 1, right = n-2; 

        int waterSum = 0;
        
        while(left <= right)
        {
            if(maxLeft < maxRight)
            {
                if(height[left] < maxLeft) 
                    waterSum += (maxLeft - height[left]);
                else
                    maxLeft = height[left];

                left++;
            }
            else
            {
                if(height[right] < maxRight) 
                    waterSum += (maxRight - height[right]); 
                else
                    maxRight = height[right]; 

                right--;
            }
        }

        return waterSum;
    }
};
// min(maxLeft, maxRight) decides the max possible water level at that index