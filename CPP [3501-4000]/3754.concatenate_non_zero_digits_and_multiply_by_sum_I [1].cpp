class Solution {
public:
    // T.C.=O(1), S.C.=O(1)
    long long sumAndMultiply(int n) {
        string s = to_string(n);

        string strWithoutZeros = "";
        int digitSum = 0;
        for(char ch: s){
            if(ch == '0')
                continue;

            strWithoutZeros += ch;
            digitSum += ch - '0';
        }

        return strWithoutZeros == "" ? 0 : stol(strWithoutZeros) * digitSum;
    }
};