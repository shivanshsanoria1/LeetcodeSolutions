class Solution {
public:
    string convertToBase7(int num) {
        if(num == 0)
            return "0";
        bool isNeg = num < 0 ? true : false;
        num = abs(num);
        string s = "";
        while(num > 0)
        {
            s += to_string(num % 7);
            num /= 7;
        }
        reverse(s.begin(), s.end());
        return isNeg ? "-" + s : s;
    }
};