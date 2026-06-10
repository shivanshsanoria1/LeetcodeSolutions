class Solution {
public:
    int secondHighest(string s) {
        int max1=-1, max2=-1; //max1:largest digit , max2:2nd largest digit
        for(int i=0; i<s.length(); i++)
        {
            if(s[i]>='0' && s[i]<='9')
            {
                int dig=s[i]-'0';
                if(dig > max1) //new max1 found
                {
                    max2=max1; //update max2 to max1
                    max1=dig; //update max1 to curr
                }
                else if(dig < max1 && dig > max2) //new max2 found
                    max2=dig; //update max2 to curr
            }
        }
        return max2;
    }
};