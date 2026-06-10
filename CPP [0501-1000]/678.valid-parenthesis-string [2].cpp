class Solution {
public:
    bool checkValidString(string s) { // T.C.=O(n), S.C.=O(n)
        stack<int> lefts; // to store indexes of '('
        stack<int> stars; // to store indexes of '*'
        for(int i=0; i<s.length(); i++)
        {
            if(s[i] == '(')
                lefts.push(i);
            else if(s[i] == '*')
                stars.push(i);
            else // s[i] == ')'
            {
                if(!lefts.empty()) // matching '(' found
                    lefts.pop();
                else if(!stars.empty()) // treat '*' as '('
                    stars.pop();
                else // no matching '(' found
                    return false;
            }
        }
        if(lefts.size() > stars.size()) // more '(' remaining than '*'
            return false;
        while(!lefts.empty()) // '(' are remaining
        {
            // no matching ')' found as there are no '*' remaining or
            // remaining '*' are at index lesser than the curr '(' index
            if(stars.empty() || lefts.top() > stars.top())
                return false;
            lefts.pop();
            stars.pop(); // treat '*' as ')'
        }
        // no more '(' or ')' remaining, treat the leftover '*' as ''
        return true;
    }
};