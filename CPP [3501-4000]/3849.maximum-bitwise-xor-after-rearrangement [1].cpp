class Solution {
public:
    // T.C.=O(n), S.C.=O(1)
    string maximumXor(string s, string t) {
        int ones = count(t.begin(), t.end(), '1');
        int zeros = t.length() - ones;

        string x = "";
        for(char ch: s){
            if(ch == '1'){
                if(zeros > 0){
                    zeros--;
                    x += "1";
                }else{ // ones > 0
                    ones--;
                    x += "0";
                }
            }else{ // ch == '0'
                if(ones > 0){
                    ones--;
                    x += "1";
                }else{ // zeros > 0
                    zeros--;
                    x += "0";
                }
            }
        }

        return x;
    }
};