class Solution {
public:
    int numDifferentIntegers(string word) {
        unordered_set<string> s;
        string num = "";
        for(char ch: word)
        {
            if(ch >= 'a' && ch <= 'z')
            {
                if(num.length() > 0)
                    s.insert(num);
                num = "";
            }
            else
            {
                // skip the leading zeros
                if(num.length() == 1 && num[0] == '0')
                    num = "";
                num += ch;
            }
        }
        if(num.length() > 0)
            s.insert(num);
        return s.size();
    }
};