class Solution {
public:
    // return true if string s is palindrome
    bool isPalin(string& s){
        int left = 0, right = s.length()-1;
        while(left < right)
        {
            if(s[left] != s[right])
                return false;
            left++;
            right--;
        }
        return true;
    }

    int solve(string& s, string& s1, string& s2, int i){
        if(i == s.length()) // index out of bounds in string s
        {
            int n1=s1.length(), n2=s2.length();
            return (isPalin(s1) && isPalin(s2)) ? n1*n2 : 0;
        }
        // include the ith char in s1
        s1 += s[i];
        int first = solve(s, s1, s2, i+1);
        s1.pop_back();
        // include the ith char in s2
        s2 += s[i];
        int second = solve(s, s1, s2, i+1);
        s2.pop_back();
        // skip the ith char
        int skip = solve(s, s1, s2, i+1);

        return max(skip, max(first, second));
    }

    int maxProduct(string s) { // Backtracking, T.C.=O(n*3^n)
        string s1 = "", s2 = "";
        return solve(s, s1, s2, 0);
    }
};