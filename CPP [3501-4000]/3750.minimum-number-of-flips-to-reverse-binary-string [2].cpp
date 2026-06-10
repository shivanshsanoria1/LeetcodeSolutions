class Solution {
public:
    // T.C.=O(log(n)), S.C.=O(log(n))
    int minimumFlips(int n) {
        string binStr = "";
        while(n > 0){
            binStr += n % 2 == 0 ? '0' : '1';
            n /= 2;
        }

        int flips = 0;
        for(int left=0, right=binStr.length()-1; left<right; left++, right--)
            if(binStr[left] != binStr[right])
                flips += 2;

        return flips;
    }
};