class Solution {
public:
    string removeDigit(string number, char digit) {
        string ans = "";
        for(int i=0; i<number.length(); i++)
        {
            if(number[i] != digit)
                continue;
            string temp = number.substr(0, i) + number.substr(i+1);
            ans = max(ans, temp);
        }
        return ans;
    }
};