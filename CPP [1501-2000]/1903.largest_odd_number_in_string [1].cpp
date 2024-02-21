class Solution {
public:
    string largestOddNumber(string num) {
        int n = num.length();
        string ans = "";
        for(int i=n-1; i>=0; i--)
            if((num[i] - '0') % 2 == 1) // find the rightmost odd digit
            {   // substring starting at index 0 and ending at index i
                ans = num.substr(0, i+1); 
                break;
            }
        return ans;
    }
};