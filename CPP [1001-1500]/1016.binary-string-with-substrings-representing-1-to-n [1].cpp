class Solution {
private:
    string convertIntToBinaryStr(int num){
        string binStr = "";
        while(num > 0)
        {
            binStr += num & 1 ? "1" : "0";
            num >>= 1;
        }

        reverse(binStr.begin(), binStr.end());
        
        return binStr;
    }

public:
    // T.C.=O(n*(m + 30)), S.C.=O(30)
    // m: length of s
    bool queryString(string s, int n) {
        for(int i=1; i<=n; i++)
        {
            string binStr = convertIntToBinaryStr(i);
            // 'binStr' is not a substring of 's'
            if(s.find(binStr) == string::npos)
                return false;
        }

        return true;
    }
};