class Solution {
private:
    string convertIntToBin(int num){
        string numStr = "";
        while(num > 0)
        {
            numStr += to_string(num & 1);
            num = num >> 1;
        }

        reverse(numStr.begin(), numStr.end());
        return numStr;
    }

public:
    string convertDateToBinary(string date) {
        int yyyy = stoi(date.substr(0, 4));
        int mm = stoi(date.substr(5, 2));
        int dd = stoi(date.substr(8, 2));

        return convertIntToBin(yyyy) + "-" + convertIntToBin(mm) + "-" + convertIntToBin(dd);
    }
};