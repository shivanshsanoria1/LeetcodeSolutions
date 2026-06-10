class Solution {
public:
    // T.C.=O(n), S.C.=O(1)
    int minAddToMakeValid(string s) {
        int extraLeft = 0;
        int extraRight = 0;
        for(char ch: s)
        {
            if(ch == ')')
            {
                if(extraLeft > 0)
                    extraLeft--;
                else
                    extraRight++;
            }
            else // ch == '('
                extraLeft++;
        }

        return extraLeft + extraRight;
    }
};