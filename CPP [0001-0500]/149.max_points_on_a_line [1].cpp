class Solution {
public:
    // T.C.=O(n^3), S.C.=O(1)
    int maxPoints(vector<vector<int>>& points) { 
        int n=points.size();

        if(n < 3)
            return n;

        int ans = 0;

        for(int i=0; i<n-2; i++)
        {
            int x1 = points[i][0], y1 = points[i][1];

            for(int j=i+1; j<n-1; j++)
            {
                int x2 = points[j][0], y2 = points[j][1];
                // 2 points always lie on a line
                int count = 2;

                for(int k=j+1; k<n; k++)
                {
                    int x3 = points[k][0], y3 = points[k][1];

                    if((y2-y1)*(x3-x2) == (y3-y2)*(x2-x1))
                        count++;
                }

                ans = max(ans, count);
            }
        }

        return ans;
    }
};
/*
# 3 points A(x1,y1), B(x2,y2), C(x3,y3) lie on a line if 
# slope of line between A and B = slope of line between B and C
  (y2-y1)/(x2-x1) = (y3-y2)/(x3-x2)
  (y2-y1)*(x3-x2) = (y3-y2)*(x2-x1)
*/