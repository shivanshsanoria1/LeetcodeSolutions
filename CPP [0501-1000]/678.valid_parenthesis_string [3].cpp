class Solution {
public:
    bool checkValidString(string s) { // Greedy, T.C.=O(n), S.C.=O(1)
        int leftMax = 0; // max '(' after balancing the ')'
        int leftMin = 0; // min '(' after balancing the ')'
        for(char ch: s)
        {
            if(ch == '(')
            {
                leftMax++;
                leftMin++;
            }
            else if(ch == ')')
            {
                leftMax--;
                leftMin--;
            }
            else // ch == '*'
            {
                leftMax++; // treat '*' as '('
                leftMin--; // treat '*' as ')'
            }

            if(leftMax < 0) // ')' cannot be balanced by '(' and '*'
                return false;
            if(leftMin < 0) // limit leftMin to 0
                leftMin = 0;
        }
        return leftMin == 0 ? true : false;
    }
};