class Solution {
public:
    bool winnerOfGame(string colors) {
        int countA = 0, countB = 0; // length of longest subarray of A's or B's
        int alice = 0, bob = 0;
        for(char color: colors)
        {
            if(color == 'A')
            {
                countA++;
                if(countB > 2)
                    bob += countB - 2;
                countB = 0;
            }
            else // color == 'B'
            {
                countB++;
                if(countA > 2)
                    alice += countA - 2;
                countA = 0;
            }
        }
        if(countB > 2)
            bob += countB - 2;
        else if(countA > 2)
            alice += countA - 2;
        return alice == bob ? false : alice > bob;
    }
};