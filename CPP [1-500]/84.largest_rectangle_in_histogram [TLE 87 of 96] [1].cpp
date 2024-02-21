class Solution {
public:
    int largestRectangleArea(vector<int>& heights) { //T.C.=O(n^2) , S.C.=O(1)
        int n=heights.size(), left, right, cl, cr, count, curr_area, max_area=0;
        for(int i=0; i<n; i++)
        {
            cl=0,cr=0;
            left=i-1;
            right=i+1;
            while(left>=0 && heights[left]>=heights[i])
            {
                cl++;
                left--;
            }
            while(right<=n-1 && heights[right]>=heights[i])
            {
                cr++;
                right++;
            }
            count=cl+1+cr;
            curr_area=count*heights[i];
            if(curr_area > max_area)
                max_area=curr_area;
        }
        return max_area;
    }
};