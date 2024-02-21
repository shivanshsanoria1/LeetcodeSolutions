class Solution {
public:
    int func(char x)
    {
        if(x=='1')
            return 1;
        return 0;
    }
    string addBinary(string a, string b) {
        int n1=a.length(), n2=b.length();
        int i=n1-1, j=n2-1, carry=0, sum;
        string c="";
        while(i>=0 && j>=0)
        {
            sum= func(a[i]) + func(b[j]) + carry;
            switch(sum)
            {
                case 0:
                    c=c+"0";
                    carry=0;
                    break;
                case 1:
                    c=c+"1";
                    carry=0;
                    break;
                case 2:
                    c=c+"0";
                    carry=1;
                    break;
                case 3:
                    c=c+"1";
                    carry=1;
                    break;
            }
            i--;
            j--;
        }
        if(i!=-1) // if string a is longer
        {
            while(i>=0)
            {
                sum= func(a[i]) + carry;
                switch(sum)
                {
                    case 0:
                        c=c+"0";
                        carry=0;
                        break;
                    case 1:
                        c=c+"1";
                        carry=0;
                        break;
                    case 2:
                        c=c+"0";
                        carry=1;
                        break;
                    case 3:
                        c=c+"1";
                        carry=1;
                        break;
                }
                i--;
            }
        }
        else if(j!=-1) // if string b is longer
        {
            while(j>=0)
            {
                sum= func(b[j]) + carry;
                switch(sum)
                {
                    case 0:
                        c=c+"0";
                        carry=0;
                        break;
                    case 1:
                        c=c+"1";
                        carry=0;
                        break;
                    case 2:
                        c=c+"0";
                        carry=1;
                        break;
                    case 3:
                        c=c+"1";
                        carry=1;
                        break;
                }
                j--;
            }
        }
        if(carry==1) // if carry is generated beyond the MSB of longer string
            c=c+"1";
        reverse(c.begin(),c.end());
        return c;
    }
};