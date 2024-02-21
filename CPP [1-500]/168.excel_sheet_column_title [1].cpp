class Solution {
public:
    string convertToTitle(int columnNumber) { // T.C.=O(log26(n))
        string ans = "";
        while(columnNumber > 0) // rem in range [0,25] matches with char [A,Z]
        {
            columnNumber--;
            int rem = columnNumber % 26;
            columnNumber /= 26;
            ans += char('A' + rem);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};