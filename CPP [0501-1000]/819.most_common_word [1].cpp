class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        string ans="";
        int n= paragraph.length(), max_freq=0;
        for(int i=0; i<n; i++) //convert string to lowercase
            paragraph[i]= tolower(paragraph[i]);
        unordered_set<string> s(banned.begin(),banned.end()); //add banned words into a set
        unordered_map<string,int> mp; //word -> freq
        string word="";
        for(int i=0; i<n+1; i++) //extract words from paragraph
        {
            if(i<n && paragraph[i] >= 'a' && paragraph[i]<='z')
                word += paragraph[i];
            else
            {
                if(word!="" && s.find(word) == s.end()) //curr word is not present in banned words set
                {
                    mp[word]++; //update freq of curr word
                    if(mp[word] > max_freq) //new max freq found
                    {
                        max_freq= mp[word]; //update max freq
                        ans=word;
                    }
                }
                word=""; //reset 'word'
            }
        }
        return ans;
    }
};