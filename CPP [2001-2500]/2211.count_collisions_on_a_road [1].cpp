class Solution {
public:
    // T.C.=O(n), S.C.=O(1)
    int countCollisions(string directions) {
        // count of Right moving cars
        int r = 0; 
        // Stationary car caused due to collision
        bool s = false;
        int collisions = 0;

        for(char curr: directions)
        {
            if(curr == 'S')
            {
                s = true;
                collisions += r;
                r = 0;
            }
            else if(curr == 'L')
            {
                if(r > 0)
                {
                    s = true;
                    collisions += r + 1;
                    r = 0;
                }
                else if(s)
                    collisions++;
            }
            else // curr == 'R'
                r++; 
        }

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