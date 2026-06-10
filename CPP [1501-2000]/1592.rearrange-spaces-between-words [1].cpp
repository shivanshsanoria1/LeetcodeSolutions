class Solution {
public:
    string reorderSpaces(string text) {
        int n=text.length();
        vector<string> words;
        int totalSpaces = 0;
        int i = 0;
        while(i < n)
        {
            if(text[i] == ' ')
            {
                totalSpaces++;
                i++;
            }
            else
            {
                string word = "";
                while(i < n && text[i] != ' ')
                {
                    word += text[i];
                    i++;
                }
                words.push_back(word);
            }
        }

        int totalWords = words.size();
        if(totalWords == 1)
        {
            string lastSpaceStr = "";
            while(totalSpaces--)
                lastSpaceStr += " ";
            return words[0] + lastSpaceStr;
        }
        
        int space = totalSpaces / (totalWords - 1);
        string spaceStr = "";
        while(space--)
            spaceStr += " ";
        int lastSpace = totalSpaces % (totalWords - 1);
        string lastSpaceStr = "";
        while(lastSpace--)
            lastSpaceStr += " ";
        
        string ans = "";
        for(int i=0; i<totalWords-1; i++)
            ans += words[i] + spaceStr;
        ans += words[totalWords-1] + lastSpaceStr;
        return ans;
    }
};