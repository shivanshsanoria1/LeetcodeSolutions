class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int fixed = 0, notFixed = 0;
        for(char dir: moves)
        {
            if(dir == 'L')
                fixed--;
            else if(dir == 'R')
                fixed++;
            else // dir == '_'
                notFixed++;
        }
        return abs(fixed) + notFixed;
    }
};