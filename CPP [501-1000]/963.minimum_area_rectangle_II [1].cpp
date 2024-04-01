class Solution {
private:
    typedef long long int lli;

public:
    // T.C.=O(n^3), S.C.=O(n)
    double minAreaFreeRect(vector<vector<int>>& points) {
        // { hash of point }
        unordered_set<string> s;

        // add the hash of each point in the set
        for(vector<int>& point: points)
        {
            int x = point[0], y = point[1];
            s.insert(to_string(x) + "#" + to_string(y));
        }

        int n=points.size();
        double minArea = DBL_MAX;

        for(int i=0; i<n-2; i++)
            for(int j=i+1; j<n-1; j++)
                for(int k=j+1; k<n; k++)
                {
                    // 3 points A(x1,y1), B(x2,y2), C(x3,y3) which 
                    // hopefully form a right angle triangle ABC
                    int x1 = points[i][0], y1 = points[i][1];
                    int x2 = points[j][0], y2 = points[j][1];
                    int x3 = points[k][0], y3 = points[k][1];

                    // square of the length of each side of triangle ABC
                    // dist12_2: (AB)^2, dist23_2: (BC)^2, dist31_2: (CA)^2 
                    lli dist12_2 = (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2);
                    lli dist23_2 = (x2-x3)*(x2-x3) + (y2-y3)*(y2-y3);
                    lli dist31_2 = (x3-x1)*(x3-x1) + (y3-y1)*(y3-y1);

                    // 4th point D(x4,y4) required to form the rectangle ABCD
                    int x4 = -1, y4 = -1;

                    // area of the rectangle ABCD
                    double area = 0;

                    // right angle at B(x2,y2)
                    if(dist12_2 + dist23_2 == dist31_2)
                    {
                        x4 = x1 + x3 - x2;
                        y4 = y1 + y3 - y2;
                        area = sqrt(dist12_2) * sqrt(dist23_2);
                    }
                    // right angle at C(x3,y3)
                    else if(dist23_2 + dist31_2 == dist12_2)
                    {
                        x4 = x1 + x2 - x3;
                        y4 = y1 + y2 - y3;
                        area = sqrt(dist23_2) * sqrt(dist31_2);
                    }
                    // right angle at A(x1,y1)
                    else if(dist31_2 + dist12_2 == dist23_2)
                    {
                        x4 = x2 + x3 - x1;
                        y4 = y2 + y3 - y1;
                        area = sqrt(dist31_2) * sqrt(dist12_2);
                    }
                    
                    string hash = to_string(x4) + "#" + to_string(y4);

                    // point D(x4,y4) found in set
                    if(s.find(hash) != s.end())
                        minArea = min(minArea, area);
                }
        
        return minArea == DBL_MAX ? 0 : minArea;
    }
};
/*
# For a rectangle ABCD with coordinates:
  A(x1,y1), B(x2,y2), C(x3,y3), D(x4,y4)

  The point of intersection of diagonals AC and BD
  (using the midpoint formula) is: 
  ((x1+x3)/2, (y1+y3)/2) or ((x2+x4)/2, (y2+y4)/2)

  since both these are the same,
  (x1+x3)/2 = (x2+x4)/2 and (y1+y3)/2 = (y2+y4)/2

  thus,
  x1+x3 = x2+x4 and y1+y3 = y2+y4

# area of rect ABCD = 2 * area of triangle ABC
*/