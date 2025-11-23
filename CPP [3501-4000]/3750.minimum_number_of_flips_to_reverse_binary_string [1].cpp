class Solution {
public:
    // T.C.=O(log(n)), S.C.=O(log(n))
    int minimumFlips(int n) {
        string binStr = "";
        while(n > 0){
            binStr += n % 2 == 0 ? '0' : '1';
            n /= 2;
        }

        string revBinStr = binStr;
        reverse(revBinStr.begin(), revBinStr.end());

        int flips = 0;
        for(int i=0; i<binStr.length(); i++)
            if(binStr[i] != revBinStr[i])
                flips++;

        return flips;
    }
};