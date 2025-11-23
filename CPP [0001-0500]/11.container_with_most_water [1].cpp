class Solution {
public:
    int maxArea(vector<int>& height) { // T.C.=O(n)
        int n=height.size(), left=0, right=n-1, h, area, max_area=0;
        while(left < right)
        {
            if(height[left] < height[right])
            {
                h = height[left];
                area = h*(right-left);
                left++;
            }
            else
            {
                h = height[right];
                area = h*(right-left);
                right--;
            }
            max_area = max(max_area,area);
        }
        return max_area;
    }
};