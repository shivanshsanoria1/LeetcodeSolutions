class Solution {
public:
    bool judgeCircle(string moves) {
        int x=0, y=0;
        for(char dir: moves)
        {
            if(dir == 'U')
                x--;
            else if(dir == 'D')
                x++;
            else if(dir == 'L')
                y--;
            else // dir == 'R'
                y++;
        }
        return x == 0 && y == 0 ? true : false;
    }
};