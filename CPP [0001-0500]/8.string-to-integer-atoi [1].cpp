class Solution {
private:
    // removes the leading char 'ch' from string
    string removeLeadingChar(string s, char ch){
        int i=0;
        for(; i<s.length(); i++)
            if(s[i] != ch)
                break;
        
        return s.substr(i);
    }

    string extractLeadingDigits(string s){
        string num = "";
        for(char ch: s)
        {
            if(ch < '0' || ch > '9')
                break;
            num += ch;
        } 
        
        return num;
    }

    int stringToInt(string s, int sign){
        if(s.length() > 10)
            return sign == 1 ? INT_MAX : INT_MIN;
        else if(s.length() == 10)
        {
            if(sign == 1 && s >= "2147483647")
                return INT_MAX;
            if(sign == -1 && s >= "2147483648")
                return INT_MIN;
        }

        int num = 0;
        for(char ch: s)
        {
            num *= 10;
            num += ch - '0';
        }

        return sign * num;
    }

public:
    int myAtoi(string s) {
        // remove the leading whitespaces from s
        string s1 = removeLeadingChar(s, ' ');
        if(s1.empty())
            return 0;
        
        // determine the sign of number
        int sign = 1;
        if(s1[0] == '+')
            sign = 1;
        else if(s1[0] == '-')
            sign = -1;
        // not a sign or digit
        else if(s1[0] < '0' || s1[0] > '9')
            return 0;
        
        // remove the sign from s1
        string s2 = s1[0] == '+' || s1[0] == '-' ? s1.substr(1) : s1;
        if(s2.empty())
            return 0;
        
        // extract the leading digits ['0' to '9'] from s2
        string s3 = extractLeadingDigits(s2);
        if(s3.empty())
            return 0;

        // remove the leading 0's from s3
        string s4 = removeLeadingChar(s3, '0');
        if(s4.empty())
            return 0;

        // convert s4 to integer
        return stringToInt(s4, sign);
    }
};