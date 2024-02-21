class Solution {
public:
    string toHex(int num) {
        if(num==0)
            return "0";
        string hex="", table="0123456789abcdef";
        int rem;
        unsigned int n=num; //to handle -ive numbers
        while(n > 0)
        {
            rem=n%16;
            hex += table[rem];
            n=n/16;
        }
        reverse(hex.begin(),hex.end());
        return hex;
    }
};