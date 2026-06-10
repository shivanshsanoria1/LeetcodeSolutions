class Solution {
public:
    bool squareIsWhite(string coordinates) {
        int row=coordinates[1]-'0';
        int col=coordinates[0]-'a';
        if((row+col)%2==0) //white tile
            return true;
        return false; //black tile
    }
};