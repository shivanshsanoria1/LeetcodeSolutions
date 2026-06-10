class Solution {
public:
    string reformatNumber(string number) {
        string num = "";
        for(char ch: number)
            if(ch >= '0' && ch <= '9')
                num += ch;

        int n=num.length();
        int end = n-3; // n % 3 == 0
        if(n % 3 == 1)
            end = n-4;
        else if(n % 3 == 2)
            end = n-2;
        string ans = "";
        string group = "";
        for(int i=0; i<end; i++)
        {
            group += num[i];
            if(i % 3 == 2)
            {
                ans += group + "-";
                group = "";
            }
        }

        if(n % 3 == 0)
            ans = ans + num[n-3] + num[n-2] + num[n-1];
        else if(n % 3 == 1)
            ans = ans + num[n-4] + num[n-3] + "-" + num[n-2] + num[n-1];
        else // n % 3 == 2
            ans = ans + num[n-2] + num[n-1];

        return ans;
    }
};