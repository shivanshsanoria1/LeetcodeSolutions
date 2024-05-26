class Solution {
public:
    // T.C.=O(n), S.C.=O(1)
    string compressedString(string word) {
        string comp = "";

        char prev = '#';
        int count = 0;

        // to handle the last group case
        word += "#";

        for(char ch: word)
        {
            if(ch == prev)
            {
                count++;
                continue;
            }
            
            if(prev != '#')
            {
                while(count > 9)
                {
                    comp += "9";
                    comp += prev;
                    count -= 9;
                }
                comp += to_string(count);
                comp += prev;
            }

            // reset count
            count = 1;
            // update prev-char
            prev = ch;
        }

        // get the original string back
        word.pop_back();

        return comp;
    }
};