class Solution {
public:
    // 0: s1 == s2, 1: s1 > s2, -1: s1 < s2
    int compareStrings(string &s1, string &s2){
        int n1 = s1.length();
        int n2 = s2.length();
        if(n1 > n2)
            return 1;
        if(n1 < n2)
            return -1;
        for(int i=0; i<n1; i++)
        {
            if(s1[i] > s2[i])
                return 1;
            else if(s1[i] < s2[i])
                return -1;
        }
        return 0;
    }

    string largestOddNumber(string num) {
        int n = num.length();
        string ans = "";
        for(int i=0; i<n; i++)
        {
            if(num[i] == '0') // skip the substring with leading 0's
                continue;
            for(int j=n-1; j>=i; j--)
            {
                if((num[j] - '0') % 2 == 0) // skip the substring ending with even digit
                    continue;
                string sub = num.substr(i, j-i+1);
                if(compareStrings(ans, sub) < 0) // ans is smaller than curr substring
                    ans = sub;
            }
        }
        return ans;
    }
};