class Solution {
public:
    int mostWordsFound(vector<string>& sentences) {
        int max_words=0, word;
        for(int i=0; i<sentences.size(); i++)
        {
            word=1;
            for(int j=0; j<sentences[i].size(); j++)
                if(sentences[i][j]==' ')
                    word++;
            max_words= max(max_words,word);
        }
        return max_words;
    }
};