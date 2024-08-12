class Solution {
public:
    // T.C.=O(c), S.C.=O(1)
    int finalPositionOfSnake(int n, vector<string>& commands) {
        int i = 0, j = 0;
        for(string& command: commands)
        {
            if(command == "UP")
                i--;
            else if(command == "DOWN")
                i++;
            else if(command == "LEFT")
                j--;
            else // command == "RIGHT"
                j++;
        }

        return i*n + j;
    }
};