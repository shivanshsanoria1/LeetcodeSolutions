class Solution {
public:
    int maxNumberOfBalloons(string text) {
        int b=0, a=0, l=0, o=0, n=0;
        for(char ch: text)
        {
            if(ch == 'b')
                b++;
            else if(ch == 'a')
                a++;
            else if(ch == 'l')
                l++;
            else if(ch == 'o')
                o++;
            else if(ch == 'n')
                n++;
        }
        int words = INT_MAX;
        words = min(words, b);
        words = min(words, a);
        words = min(words, l/2);
        words = min(words, o/2);
        words = min(words, n);
        return words;
    }
};