class Solution {
public:
    int countGoodRectangles(vector<vector<int>>& rectangles) {
        int max_side=INT_MIN, c=0;
        for(int i=0; i<rectangles.size(); i++)
        {
            int sq= min(rectangles[i][0],rectangles[i][1]); //curr square side
            if(sq > max_side) //new max side found
            {
                max_side=sq; //update max side
                c=1; //reset count
            }
            else if(sq == max_side) //another curr max side found
                c++; //increment count
        }
        return c;
    }
};