class Solution {
public:
    bool solve(string& s, int i, int count){
        if(i == s.length()) // reached the end of string
            return count == 0 ? true : false;
        if(count < 0) // more ')' than '('
            return false;
        if(s[i] == '(')
            return solve(s, i+1, count + 1);
        if(s[i] == ')')
            return solve(s, i+1, count - 1);
        // '*' can be '(', ')', ''
        bool left = solve(s, i+1, count + 1);
        bool right = solve(s, i+1, count - 1);
        bool skip = solve(s, i+1, count);
        return left || right || skip;
    }

    bool checkValidString(string s) { // Recursion, T.C.=O(3^n)
        return solve(s, 0, 0);
    }
};
// count: keeps track of num of '(' which do not have a matching ')'