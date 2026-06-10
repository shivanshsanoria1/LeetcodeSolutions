class Solution {
private:
    string convertTo4DigitString(int num){
        string s = to_string(num);
        int leadingZerosCount = 4 - s.length();
        string leadingZeros = string(leadingZerosCount, '0');

        return leadingZeros + s;
    }

public:
    int generateKey(int num1, int num2, int num3) {
        string s1 = convertTo4DigitString(num1);
        string s2 = convertTo4DigitString(num2);
        string s3 = convertTo4DigitString(num3);
        
        string ans = "";
        for(int i=0; i<4; i++)
        {
            char minDigit = min(s1[i], min(s2[i], s3[i]));
            ans += minDigit;
        }

        return stoi(ans);
    }
};