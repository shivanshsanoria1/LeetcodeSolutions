class Solution {
public:
    string getDigitSum(string& s){
        if(s.length() == 0)
            return "";
        int sum = 0;
        for(char ch: s)
            sum += ch - '0';
        return to_string(sum);
    }

    string digitSum(string s, int k) {
        while(s.length() > k)
        {
            string temp = "";
            string num = "";
            for(int i=0; i<s.length(); i++)
            {
                if(i % k == 0)
                {
                    temp += getDigitSum(num);
                    num = "";
                }
                num += s[i];
            }
            temp += getDigitSum(num);
            s = temp;
        }
        return s;
    }
};