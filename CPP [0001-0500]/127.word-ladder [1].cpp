class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) { // BFS
        unordered_set<string> dict(wordList.begin(), wordList.end());
        queue<string> q;
        dict.erase(beginWord); // remove the begin word from dictionary
        q.push(beginWord);
        int level = 0;
        while(!q.empty())
        {
            int size = q.size();
            level++;
            while(size--)
            {
                string currWord = q.front();
                q.pop();
                if(currWord == endWord) // found the end word
                    return level;
                // change each char of curr word (one at a time) from 'a' to 'z'
                // and check if it is found in dictionary or not
                for(char& currChar: currWord)
                {
                    char originalChar = currChar; // save the original char of curr word
                    for(char ch='a'; ch<='z'; ch++)
                    {
                        currChar = ch; // change the currr char in range ['a', 'z']
                        if(dict.find(currWord) == dict.end()) // not found in dict
                            continue;
                        dict.erase(currWord);
                        q.push(currWord);
                    }
                    currChar = originalChar; // restore the original char of curr word
                }
            }
        }
        return 0; // cannot reach the end word from the begin word
    }
};
// T.C.=O(n*w*26), S.C.=O(n)
// n: num of words in wordList[], w: word length