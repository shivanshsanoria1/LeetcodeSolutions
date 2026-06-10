class Solution {
public:
    // T.C.=O(sqrt(min(red, blue))), S.C.=O(1)
    int maxHeightOfTriangle(int red, int blue) {
        // calculate the height starting with the blue ball
        int r = red , b = blue;
        int height1 = 0;
        for(int i=1; r >= 0 && b >= 0; i++)
        {
            if(i % 2 == 1)
                b -= i;
            else
                r -= i;

            height1 = i;
        }

        // calculate the height starting with the red ball
        r = red , b = blue;
        int height2 = 0;
        for(int i=1; r >= 0 && b >= 0; i++)
        {
            if(i % 2 == 1)
                r -= i;
            else
                b -= i;

            height2 = i;
        }

        // -1 is done since each for-loop stops when 
        // either of 'r' or 'b' becomes -ive, 
        // so the actual value of height is 1 less
        return max(height1 - 1, height2 - 1);
    }
};