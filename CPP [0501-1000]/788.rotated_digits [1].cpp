class Solution {
private:
    bool isValid(int num) {
        string strNum = to_string(num);
        string strRotNum = "";

        for(char dig: strNum)
        {
            if(dig == '3' || dig == '4' || dig == '7')
                return false;

            if(dig == '2')
                strRotNum += "5";
            else if(dig == '5')
                strRotNum += "2";
            else if(dig == '6')
                strRotNum += "9";
            else if(dig == '9')
                strRotNum += "6";
            else // dig == '0', '1', '8'
                strRotNum += dig;
        }

        return num != stoi(strRotNum);
    }

public:
    // T.C.=O(n), S.C.=O(1)
    int rotatedDigits(int n) {
        int count = 0;
        for(int i=1; i<=n; i++)
            if(isValid(i))
                count++;
        return count;
    }
};
