class Solution {
public:
    string intToRoman(int num) {
        string ans="";
        vector<int> value = {1,4,5,9,10,40,50,90,100,400,500,900,1000};
        vector<string> roman = {"I","IV","V","IX","X","XL","L","XC","C","CD","D","CM","M"};
        for(int i=12; i>=0; i--)
        {
            while(num - value[i] >=0)
            {
                num -= value[i];
                ans += roman[i];
            }
        }
        return ans;
    }
};