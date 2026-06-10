class Solution {
public:
    string maxValue(string n, int x) {
        bool isNeg = n[0] == '-';
        string maxNum = "";

        if(isNeg)
        {
            maxNum += "-";
            for(int i=1; i<n.length(); i++)
            {
                if(n[i] - '0' > x)
                {
                    maxNum += to_string(x) + n.substr(i);
                    break;
                }
                maxNum += n[i];
            }
        }
        else
        {
            for(int i=0; i<n.length(); i++)
            {
                if(n[i] - '0' < x)
                {
                    maxNum += to_string(x) + n.substr(i);
                    break;
                }
                maxNum += n[i];
            }
        }

        if(maxNum.length() == n.length())
            maxNum += to_string(x);

        return maxNum;
    }
};