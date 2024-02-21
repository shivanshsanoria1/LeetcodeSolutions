class Solution {
public:
    bool areNumbersAscending(string s) {
        int n=s.length();
        int prevNum = -1;
        int i=0;
        while(i < n)
        {
            string num = "";
            while(s[i] >= '0' && s[i] <= '9')
            {
                num += s[i];
                if(i == n-1)
                    break;
                i++;
            }
            i++;
            if(num.length() == 0)
                continue;
            if(prevNum >= stoi(num))
                return false;
            prevNum = stoi(num);
        }
        return true;
    }
};