class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        int len=word.length();
        int count = 0;
        for(string& pattern: patterns)
            for(int i=0; i<len; i++)
            {
                string s = "";
                bool patternFound = false;
                for(int j=i; j<len; j++)
                {
                    s += word[j];
                    if(s == pattern)
                    {
                        count++;
                        patternFound = true;
                        break;
                    }
                }
                if(patternFound)
                    break;
            }
        return count;
    }
};