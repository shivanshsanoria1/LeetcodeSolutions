class Solution {
public:
    string intToRoman(int num) {
        string ans="";
        vector<pair<int,string>> vec={{1,"I"},{4,"IV"},{5,"V"},{9,"IX"},{10,"X"},{40,"XL"},{50,"L"},{90,"XC"},{100,"C"},{400,"CD"},{500,"D"},{900,"CM"},{1000,"M"}};
        int i=12; //last index
        while(i>=0 && num > 0)
        {
            if(num - vec[i].first >= 0)
            {
                num -= vec[i].first;
                ans += vec[i].second;
            }
            else
                i--;
        }
        return ans;
    }
};