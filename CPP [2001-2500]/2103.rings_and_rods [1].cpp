class Solution {
public:
    int countPoints(string rings) {
        vector<bool> red(10, false);
        vector<bool> green(10, false);
        vector<bool> blue(10, false);

        for(int i=0; i<rings.length(); i += 2)
        {
            char color = rings[i];
            int idx = rings[i+1] - '0';
            if(color == 'R')
                red[idx] = true;
            else if(color == 'G')
                green[idx] = true;
            else // color == 'B'
                blue[idx] = true;
        }

        int count = 0;
        for(int i=0; i<10; i++)
            if(red[i] && green[i] && blue[i])
                count++;
        return count;
    }
};