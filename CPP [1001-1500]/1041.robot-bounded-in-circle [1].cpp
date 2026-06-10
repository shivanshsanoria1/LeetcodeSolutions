class Solution {
public:
    bool isRobotBounded(string instructions) {
        int x=0, y=0, dir=0;
        for(char ch: instructions)
        {
            if(ch == 'L')
                dir = (dir + 1) % 4;
            else if(ch == 'R')
                dir = (dir - 1 + 4) % 4;
            else // ch == 'G'
            {
                if(dir == 0) // north
                    y++;
                else if(dir == 1) // west
                    x--;
                else if(dir == 2) // south
                    y--;
                else // dir == 3, east
                    x++;
            }
        }
        return (x == 0 && y == 0) || dir != 0 ? true : false;
    }
};
/*
# circle is formed when-
# end coordinates are the same as initial coordinates or
# end direction is different from the initial direction
*/