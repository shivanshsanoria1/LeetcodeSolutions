class Solution {
public:
    bool canAliceWin(int n) {
        int turn = 10;
        while(n >= 0)
        {
            n -= turn;
            if(n < 0)
                return turn % 2 == 1;
            turn--;
        }

        return true;
    }
};