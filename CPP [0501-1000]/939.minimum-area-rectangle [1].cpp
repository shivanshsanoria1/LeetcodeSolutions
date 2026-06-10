class Solution {
private:
    // sort by x value and then by y value if x value is same
    static bool cmp(vector<int>& a, vector<int>& b){
        int x1 = a[0], y1 = a[1];
        int x2 = b[0], y2 = b[1];
        return x1 == x2 ? y1 < y2 : x1 < x2;
    }

public:
    // T.C.=O(n^4), S.C.=O(1)
    int minAreaRect(vector<vector<int>>& points) {
        int n=points.size();
        // atleast 4 points are needed to form a rectangle
        if(n < 4)
            return 0;

        sort(points.begin(), points.end(), cmp);
        int minArea = INT_MAX;

        for(int i=0; i<n-3; i++)
        {
            int x1 = points[i][0], y1 = points[i][1];
            for(int j=i+1; j<n-2; j++)
            {
                int x2 = points[j][0], y2 = points[j][1];
                if(x1 != x2)
                    continue;
                for(int k=j+1; k<n-1; k++)
                {
                    int x3 = points[k][0], y3 = points[k][1];
                    if(y1 != y3)
                        continue;
                    for(int l=k+1; l<n; l++)
                    {
                        int x4 = points[l][0], y4 = points[l][1];
                        if(x3 != x4 || y2 != y4)
                            continue;
                        minArea = min(minArea, (x3-x1)*(y2-y1));
                    }
                }
            }
        }

        return minArea == INT_MAX ? 0 : minArea;
    }
};

/*
B (x2,y2) ----- (x4,y4) D
    |              |
    |              |
    |              |
A (x1,y1) ----- (x3,y3) C

# points A, B, C, D are in sorted order
# for ABCD to be a rectangle:
  x1 == x2 && x3 == x4 && y1 == y3 && y2 == y4
*/