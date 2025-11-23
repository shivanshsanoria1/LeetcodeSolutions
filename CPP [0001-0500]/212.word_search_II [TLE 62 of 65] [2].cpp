class Solution {
private:
    bool basicChecks(vector<vector<char>>& board, string& word) {
        int m=board.size(), n=board[0].size();
        // max possible length of 'word' is the total
        // num of chars in 'board', ie, m*n
        if(word.length() > m*n)
            return false;
        
        // check if the 'board' has greater than or equal to 
        // freq for each char apprearing in 'word'

        vector<int> freq(26, 0);

        for(int i=0; i<m; i++)
            for(int j=0; j<n; j++)
                freq[board[i][j] - 'a']++;
        
        for(char ch: word)
        {
            freq[ch - 'a']--;
            if(freq[ch - 'a'] < 0)
                return false;
        }

        return true;
    }

    bool dfs(vector<vector<char>>& board, string& word, int i, int j, int idx) {
        // word found
        if(idx == word.size()) 
            return true;

        int m=board.size(), n=board[0].size();
        // index out of bounds
        if(i<0 || i>=m || j<0 || j>=n) 
            return false;
        // character does not match
        if(board[i][j] != word[idx])
            return false;

        // save the curr element
        char ch = board[i][j];
        // mark the curr element as visited
        board[i][j] = '*';

        bool up = dfs(board, word, i-1, j, idx + 1);
        bool down = dfs(board, word, i+1, j, idx + 1);
        bool left = dfs(board, word, i, j-1, idx + 1);
        bool right = dfs(board, word, i, j+1, idx + 1);

        // mark the curr element as unvisited
        board[i][j] = ch; 

        return up || down || left || right;
    }

public:
    // T.C.=O(w*(m*n)^2), S.C.=O(m*n)
    // Backtracking
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        int m=board.size(), n=board[0].size();
        vector<string> ans;

        for(string& word: words)
        {
            // basic checks failed
            if(!basicChecks(board, word))
                continue;

            // run dfs() for each element in board
            for(int i=0; i<m; i++)
            {
                bool isFound = false;

                for(int j=0; j<n; j++)
                    if(dfs(board, word, i, j, 0))
                    {
                        ans.push_back(word);
                        isFound = true;
                        break;
                    }
                    
                if(isFound)
                    break;
            }
        }

        return ans;
    }
};