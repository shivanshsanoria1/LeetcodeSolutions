class Solution {
public:
    // returns index of char 'ch' in the string 'order'
    int findIndex(string &order, char ch){
        for(int i=0; i<order.length(); i++)
            if(order[i] == ch)
                return i;
        return -1;
    }
    
    bool isAlienSorted(vector<string>& words, string order) {
        for(int i=0; i<words.size()-1; i++)
        {
            string word1 = words[i];
            string word2 = words[i+1];
            int index = 0;
            int len = min(word1.length(), word2.length());
            while(index < len && word1[index] == word2[index])
                index++;
            if(findIndex(order, word1[index]) > findIndex(order, word2[index]))
                return false;
        }
        return true;
    }
};