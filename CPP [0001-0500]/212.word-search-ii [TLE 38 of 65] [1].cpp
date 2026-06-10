class Solution {
private:
    void dfs(vector<vector<char>>& board, unordered_map<string, bool>& visited, string& word, int& foundCount, int i, int j){
        int m=board.size(), n=board[0].size();
        // index out of bounds
        if(i<0 || i>=m || j<0 || j>=n) 
            return;
        // already visited char
        if(board[i][j] == '*')
            return;
        // all words found in board
        if(foundCount == visited.size())
            return;

        // save the curr char
        char ch = board[i][j];
        // mark the curr char as visited
        board[i][j] = '*';
        // add the curr char to curr word
        word += ch;
        // curr word found in map
        if(visited.find(word) != visited.end() && visited[word] == false)
        {
            visited[word] = true;
            foundCount++;
        }

        dfs(board, visited, word, foundCount, i-1, j); // up
        dfs(board, visited, word, foundCount, i+1, j); // down
        dfs(board, visited, word, foundCount, i, j-1); // left
        dfs(board, visited, word, foundCount, i, j+1); // right

        // mark the curr char as unvisited
        board[i][j] = ch;
        // remove the curr char from curr word
        word.pop_back();
    }

public:
    // T.C.=O(w + (m*n)^2), S.C.=O(w)
    // Backtracking
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        // word -> found in board or not
        unordered_map<string, bool> visited;
        // add all words in map with initial state false
        for(string& word: words)
            visited[word] = false;
        
        int m=board.size(), n=board[0].size();
        int foundCount = 0;

        // run dfs() for every element in board
        for(int i=0; i<m; i++)
        {
            string word = "";
            for(int j=0; j<n; j++)
                dfs(board, visited, word, foundCount, i, j);
        }

        vector<string> ans;

        for(auto [word, isFound]: visited)
            if(isFound)
                ans.push_back(word);
        
        return ans;
    }
};
/*
# visited map has all the words present in words[]
# visited[word] 
  = false: 'word' not found in board
  = true: 'word' found in board
*/