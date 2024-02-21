class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        vector<bool> vec(26,false); //keeps track of char present in the string allowed
        for(int i=0; i<allowed.length(); i++)
            vec[allowed[i]-'a']=true;
        int invalid=0;
        for(int i=0; i<words.size(); i++)
            for(int j=0; j<words[i].length(); j++)
                if(vec[words[i][j]-'a']==false) //invalid char found in the string words[i]
                {
                    invalid++;
                    break;
                }
        return words.size()-invalid;
    }
};