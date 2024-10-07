class Solution {
private:
    string intToBinStr(int num){
        string str = "";
        while(num > 0)
        {
            str += (num & 1 == 1) ? "1" : "0";
            num >>= 1;
        }

        reverse(str.begin(), str.end());

        return str;
    }

    int binStrToInt(string str){
        reverse(str.begin(), str.end());

        int num = 0;
        int mul = 1;
        for(char bit: str)
        {
            num += (bit == '1' ? 1 : 0) * mul;
            mul *= 2;
        }

        return num;
    }

public:
    // T.C.=O(1), S.C.=O(1)
    int maxGoodNumber(vector<int>& nums) {
        string s1 = intToBinStr(nums[0]);
        string s2 = intToBinStr(nums[1]);
        string s3 = intToBinStr(nums[2]);

        int maxVal = 0;
        maxVal = max(maxVal, binStrToInt(s1 + s2 + s3));
        maxVal = max(maxVal, binStrToInt(s1 + s3 + s2));
        maxVal = max(maxVal, binStrToInt(s2 + s1 + s3));
        maxVal = max(maxVal, binStrToInt(s2 + s3 + s1));
        maxVal = max(maxVal, binStrToInt(s3 + s1 + s2));
        maxVal = max(maxVal, binStrToInt(s3 + s2 + s1));

        return maxVal;
    }
};