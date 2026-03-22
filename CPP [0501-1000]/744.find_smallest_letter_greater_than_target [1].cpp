class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) { // T.C.=O(n), S.C.=O(1)
        for(char ch: letters)
            if(ch - target > 0)
                return ch;
        return letters[0];
    }
};