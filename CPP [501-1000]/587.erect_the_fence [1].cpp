class Solution {
private:
    // returns the point with min x coordinate (and min y coordinate in case of a tie)
    int findMinPt(vector<vector<int>>& trees){
        int start = 0;
        for(int i=1; i<trees.size(); i++)
        {
            bool cond1 = trees[i][0] < trees[start][0];
            bool cond2 = trees[i][0] == trees[start][0] && trees[i][1] < trees[start][1];

            if(cond1 || cond2)
                start = i;
        }

        return start;
    }

    // points A(x1, y1), B(x2, y2), C(x3, y3)
    // 1: AC-> is C.C.W. to AB->
    // -1: AC-> is C.W. to AB->
    // 0: AC-> and AB-> are collinear
    // CW: Clock-Wise, CCW: Counter-Clock-Wise
    int crossProduct(vector<int>& p1, vector<int>& p2, vector<int>& p3){
        int x1 = p1[0], y1 = p1[1];
        int x2 = p2[0], y2 = p2[1];
        int x3 = p3[0], y3 = p3[1];

        // AB-> x AC->
        int cp = (y3-y1)*(x2-x1) - (y2-y1)*(x3-x1);
        
        if(cp > 0)
            return 1;
        if(cp < 0)
            return -1;
        // cp == 0
        return 0; 
    }

    // points A(x1, y1), B(x2, y2), C(x3, y3)
    // 1: C is closer to A than B
    // -1: B is closer to A than C
    // 0: B and C are equidistant from A
    int distance(vector<int>& p1, vector<int>& p2, vector<int>& p3){
        int x1 = p1[0], y1 = p1[1];
        int x2 = p2[0], y2 = p2[1];
        int x3 = p3[0], y3 = p3[1];

        // Manhattan-distance is used instead of
        // Eucledian-distance for easier computataion
        int dist_AB = abs(x1-x2) + abs(y1-y2);
        int dist_AC = abs(x1-x3) + abs(y1-y3);

        if(dist_AB < dist_AC)
            return 1;
        if(dist_AB > dist_AC)
            return -1;
        // dist_AB == dist_AC
        return 0;
    }

public:
    // T.C.=O(n^2), S.C.=O(1)
    // Jarvis-March / Gift-Wrapping algo. (Convex-Hull)
    vector<vector<int>> outerTrees(vector<vector<int>>& trees) {
        int n=trees.size();
        if(n <= 3)
            return trees;
        
        int start = findMinPt(trees);
        vector<bool> inConvexHull(n, false);
        vector<int> collinearPts;
        int a = start;
        inConvexHull[a] = true;

        while(true)
        {
            int b = (a+1) % n;

            for(int c=0; c<n; c++)
            {
                if(a == c || b == c)
                    continue;
                
                // now points a,b,c are distinct 

                int cp = crossProduct(trees[a], trees[b], trees[c]);

                if(cp == 1)
                {
                    b = c;
                    collinearPts.clear();
                }
                else if(cp == 0)
                {
                    if(distance(trees[a], trees[b], trees[c]) == 1)
                    {
                        collinearPts.push_back(b);
                        b = c;
                    }
                    else
                        collinearPts.push_back(c);
                }
            }

            for(int pt: collinearPts)
                inConvexHull[pt] = true;

            a = b;
            inConvexHull[a] = true;

            if(a == start)
                break;

        };

        vector<vector<int>> convexHull;
        for(int i=0; i<n; i++)
            if(inConvexHull[i])
                convexHull.push_back(trees[i]);

        return convexHull;
    }
};