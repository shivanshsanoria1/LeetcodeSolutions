class Solution {
public:
    // T.C.=O(n), S.C.=O(1)
    int countCollisions(string directions) {
        int n=directions.length();

        // starting index while ignoring leading L's
        int startIdx = -1;
        for(int i=0; i<n; i++)
            if(directions[i] != 'L')
            {
                startIdx = i;
                break;
            }
        
        // ending index while ignoring trailing R's
        int endIdx = -1;
        for(int i=n-1; i>=0; i--)
            if(directions[i] != 'R')
            {
                endIdx = i;
                break;
            }
        
        // all L's or all R's
        if(startIdx == -1 || endIdx == -1)
            return 0;

        int collisions = 0;
        for(int i=startIdx; i<=endIdx; i++)
            if(directions[i] == 'L' || directions[i] == 'R')
                collisions++;
        
        return collisions;
    }
};

/*
9 cases of car interaction between 2 cars:

1) L S | <- <- |
2) L L | <- .  |
3) L R | <- -> |
4) S S |  . .  |
5) S L |  . <- | collision(1)
6) S R |  . -> |
7) R S | -> .  | collision(1)
8) R L | -> <- | collision(2)
9) R R | -> -> |

*/