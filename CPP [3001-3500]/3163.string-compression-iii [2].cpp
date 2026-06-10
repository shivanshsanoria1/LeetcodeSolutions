class Solution {
public:
    // T.C.=O(n), S.C.=O(1)
    string compressedString(string word) {
        string comp = "";
        char prev = '#';
        int count = 0;

        // to handle the last group case
        word += "#";
        
        for(char curr: word)
        {
            if(prev == curr)
            {
                count++;
                continue;
            }

            while(count > 9)
            {
                comp += "9";
                comp += prev;
                count -= 9;
            }

            if(count > 0)
            {
                comp += to_string(count);
                comp += prev;
            }

            // reset count
            count = 1;
            // update prev
            prev = curr;
        }

        // restore the original string
        word.pop_back();

        return comp;
    }
};