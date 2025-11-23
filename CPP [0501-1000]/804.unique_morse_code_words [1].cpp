class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        vector<string> morse={".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--",
                              "-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        unordered_set<string> s;
        for(int i=0; i<words.size(); i++)
        {
            string word="";
            for(int j=0; j<words[i].length(); j++)
                word+=morse[words[i][j]-'a'];
            s.insert(word);
        }
        return s.size();
    }
};