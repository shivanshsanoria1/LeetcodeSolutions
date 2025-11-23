class Solution {
public:
    int maxArea(vector<int>& height) { // T.C=O(n^2)
        int n=height.size(), h, max_area=0, area;
        for(int i=0; i<n; i++)
        {
            for(int j=i+1; j<n; j++)
            {
                h = min(height[i],height[j]);
                area = h*(j-i);
                max_area = max(max_area,area);
            }
        }
        return max_area;
    }
};