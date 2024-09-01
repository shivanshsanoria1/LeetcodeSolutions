class Solution {
public:
    // T.C.=O(1), S.C.=O(1)
    bool checkTwoChessboards(string coordinate1, string coordinate2) {
        int sum1 = (coordinate1[0] - 'a') + (coordinate1[1] - '0');
        int sum2 = (coordinate2[0] - 'a') + (coordinate2[1] - '0');

        return sum1 % 2 == sum2 % 2;
    }
};
// sum = odd: black, even: white