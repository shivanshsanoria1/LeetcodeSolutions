class Solution {
public:
    // T.C.=O(n^2), S.C.=O(1)
    int largestRectangleArea(vector<int>& heights) { 
        int n=heights.size();
        int maxArea = 0;

        for(int i=0; i<n; i++)
        {
            int left = i-1, right = i+1;
            int countLeft = 0, countRight = 0;

            // count the bars >= curr bar in the left-direction
            while(left >=0 && heights[left] >= heights[i])
            {
                countLeft++;
                left--;
            }

            // count the bars >= curr bar in the right-direction
            while(right <= n-1 && heights[right] >= heights[i])
            {
                countRight++;
                right++;
            }

            int width = 1 + countLeft + countRight;
            maxArea = max(maxArea, heights[i] * width);
        }

        return maxArea;
    }
};