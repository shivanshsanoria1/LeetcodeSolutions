class Solution {
public:
    int minTimeToType(string word) {
        int time = 0;
        int pos = 0;
        for(char ch: word)
        {
            int posToGo = ch - 'a';
            time += min(abs(posToGo - pos), 26 - abs(posToGo - pos));
            pos = posToGo;
        }
        return time + word.length();
    }
};