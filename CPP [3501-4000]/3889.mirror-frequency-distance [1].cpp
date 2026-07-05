class Solution {
public:
    // T.C.=O(n + 36), S.C.=O(36)
    int mirrorFrequency(string s) {
        vector<int> freqChar(26, 0);
        vector<int> freqNum(10, 0);

        for(char ch: s){
            if(isdigit(ch))
                freqNum[ch - '0']++;
            else
                freqChar[ch - 'a']++;
        }

        int sum = 0;
        for(int i=0; i<13; i++)
            sum += abs(freqChar[i] - freqChar[26-i-1]);
        for(int i=0; i<5; i++)
            sum += abs(freqNum[i] - freqNum[10-i-1]);

        return sum;
    }
};