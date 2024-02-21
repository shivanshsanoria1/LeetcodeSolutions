class Solution {
public:
    bool judgeCircle(string moves) {
        int u=0, d=0, l=0, r=0;
        for(char dir: moves)
        {
            if(dir == 'U')
                u++;
            else if(dir == 'D')
                d++;
            else if(dir == 'L')
                l++;
            else // dir == 'R'
                r++;
        }
        return u == d && l == r ? true : false;
    }
};