class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int maxDiagonal2 = 0;
        int maxArea = 0;
        for(int i=0; i<dimensions.size(); i++)
        {
            int l = dimensions[i][0];
            int b = dimensions[i][1];
            // new max diagonal found
            if(l*l + b*b > maxDiagonal2)
            {
                maxDiagonal2 = l*l + b*b;
                maxArea = l*b;
            }
            // another max diagonal found
            else if(l*l + b*b == maxDiagonal2)
                maxArea = max(maxArea, l*b);
        }
        return maxArea;
    }
};