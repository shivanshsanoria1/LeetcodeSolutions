class Solution {
public:
    bool checkString(string s) {
        int count = 0;
        for(int i=1; i<s.length(); i++)
        {
            if(s[i-1] == 'a' && s[i] == 'b')
            {
                count++;
                if(count > 1)
                    return false;
            }
            else if(s[i-1] == 'b' && s[i] == 'a')
                return false;
        }
        return true;
    }
};