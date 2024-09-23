class Solution {
public:
    // T.C.=O(n), S.C.=O(1)
    string alphabetBoardPath(string target) {
        string moves = "";
        int r = 0, c = 0;

        for(char ch: target)
        {
            int i = (ch - 'a') / 5;
            int j = (ch - 'a') % 5;

            // vertical then horizontal
            if(ch != 'z') 
            {
                if(i - r > 0)
                    moves += string(i-r, 'D');
                else if(i - r < 0)
                    moves += string(r-i, 'U');
                
                if(j - c > 0)
                    moves += string(j-c, 'R');
                else if(j - c < 0)
                    moves += string(c-j, 'L');
            }
            // horizontal then vertical
            else // ch == 'z'
            {
                if(j - c > 0)
                    moves += string(j-c, 'R');
                else if(j - c < 0)
                    moves += string(c-j, 'L');
                
                if(i - r > 0)
                    moves += string(i-r, 'D');
                else if(i - r < 0)
                    moves += string(r-i, 'U');
            }

            moves += "!";

            r = i;
            c = j;
        }

        return moves;
    }
};