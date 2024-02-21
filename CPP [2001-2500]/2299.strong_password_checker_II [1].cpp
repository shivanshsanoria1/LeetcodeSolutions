class Solution {
public:
    bool isSpecial(char ch){
        string special = "!@#$%^&*()-+";
        for(char c: special)
            if(c == ch)
                return true;
        return false;
    }

    bool strongPasswordCheckerII(string password) {
        int n=password.length();
        if(n < 8)
            return false;
        bool hasLower = false;
        bool hasUpper = false;
        bool hasDigit = false;
        bool hasSpecial = false;
        for(int i=0; i<n; i++)
        {
            if(i > 0 && password[i] == password[i-1])
                return false;
            else if(password[i] >= 'a' && password[i] <= 'z')
                hasLower = true;
            else if(password[i] >= 'A' && password[i] <= 'Z')
                hasUpper = true;
            else if(password[i] >= '0' && password[i] <= '9')
                hasDigit = true;
            else
            {
                if(isSpecial(password[i]))
                    hasSpecial = true;
                else
                    return false;
            }
        }
        return hasLower && hasUpper && hasDigit && hasSpecial;
    }
};