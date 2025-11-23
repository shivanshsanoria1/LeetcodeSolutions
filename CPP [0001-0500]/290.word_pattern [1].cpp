class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char,string> mp1; //char in string pattern -> words in string s
        unordered_map<string,char> mp2; //words in string s -> char in string pattern
        int n1=pattern.length(), n2=s.length(), spaces=0, j=0;
        for(int i=0; i<n1; i++)
        {
            string word="";
            while(j < n2) //extract word from string s
            {
                if(s[j]==' ')
                {
                    spaces++;
                    j++;
                    break;
                }
                else{
                    word+=s[j];
                    j++;
                }
            }
            
            if(mp1.find(pattern[i]) != mp1.end()) //pattern[i] present in map
            {
                if(mp1[pattern[i]] != word) //check if the new partner of pattern[i] ,ie, word
                    return false;           //is equal to its old partner ,ie, mp1[pattern[i]]
            }
            else
                mp1[pattern[i]]=word; //add pattern[i] and its partner word in map
            
            if(mp2.find(word) != mp2.end()) //word present in map
            {
                if(mp2[word] != pattern[i]) //check if the new partner of word ,ie, pattern[i]
                    return false;           //is equal to its old partner ,ie, mp2[word]
            }
            else
                mp2[word]=pattern[i]; //add word and its partner pattern[i] in map
        }
        if(n1 != spaces+1) //num of char in string pattern is not equal to num of words in string s
            return false;
        return true;
    }
};