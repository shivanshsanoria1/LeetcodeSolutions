class Solution {
public:
    int romanToInt(string s) {
        int n=0,len=s.length();
        for(int i=0; i<len; i++)
        {
                switch(s[i])
            {
                case 'I':
                    if(s[i+1]=='V' && i<len-1)
                    {
                        n=n+4;
                        i++;
                    }
                    else if(s[i+1]=='X' && i<len-1)
                    {
                        n=n+9;
                        i++;
                    }
                    else
                        n=n+1;
                    break;
                case 'V':n=n+5;
                    break;
                case 'X':
                        if(s[i+1]=='L' && i<len-1)
                    {
                        n=n+40;
                        i++;
                    }
                    else if(s[i+1]=='C' && i<len-1)
                    {
                        n=n+90;
                        i++;
                    }
                    else
                        n=n+10;
                    break;
                case 'L':n=n+50;
                    break;
                case 'C':
                        if(s[i+1]=='D' && i<len-1)
                    {
                        n=n+400;
                        i++;
                    }
                    else if(s[i+1]=='M' && i<len-1)
                    {
                        n=n+900;
                        i++;
                    }
                    else
                        n=n+100;
                    break;
                case 'D':n=n+500;
                    break;
                case 'M':n=n+1000;
                    break;

            }
        }
        return n;
    }
};