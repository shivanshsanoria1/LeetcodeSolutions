class Solution {
public:
    // T.C.=O(n^2), S.C.=O(1)
    long long interchangeableRectangles(vector<vector<int>>& rectangles) {
        int n=rectangles.size();
        long long int count = 0;

        for(int i=0; i<n-1; i++)
        {
            int w1 = rectangles[i][0], h1 = rectangles[i][1];

            for(int j=i+1; j<n; j++)
            {
                int w2 = rectangles[j][0], h2 = rectangles[j][1];

                if(w1*h2 == w2*h1)
                    count++;
            }
        }

        return count;
    }
};
/*
2 rectangles (w1, h1) and (w2, h2) are interchangeable if 
  w1/h1 = w2/h2
  w1*h2 = w2*h1
*/