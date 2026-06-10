class Solution {
public:
    string toHex(int num) {
        if(num==0)
            return "0";
        string hex="";
        int rem;
        unsigned int n=num; //to handle -ive numbers
        while(n > 0)
        {
            rem=n%16;
            if(rem < 10)
                hex += rem+'0';
            else
                hex += rem-10+'a';
            n=n/16;
        }
        reverse(hex.begin(),hex.end());
        return hex;
    }
};