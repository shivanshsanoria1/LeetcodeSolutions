class Solution {
public:
    string removeTrailingZeros(string num) {
        int len = num.length();
        int index = len-1;
        for(int i=len-1; i>=0; i--)
            if(num[i] != '0')
            {
                index = i;
                break;
            }
        return num.substr(0, index + 1);
    }
};