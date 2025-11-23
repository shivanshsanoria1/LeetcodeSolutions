class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<unordered_set<int>> row(9); //to keep track of elements present in a row
        vector<unordered_set<int>> col(9); //to keep track of elements present in a col
        vector<unordered_set<int>> box(9); //to keep track of elements present in a box
        for(int i=0; i<9; i++)
            for(int j=0; j<9; j++)
            {
                if(board[i][j] == '.')
                    continue;
                int curr= board[i][j]-'0';
                if(row[i].find(curr) != row[i].end()) //found in 'row[i]' set
                    return false;
                if(col[j].find(curr) != col[j].end()) //found in 'col[j]' set
                    return false;
                int box_index= (i/3)*3 + j/3;
                if(box[box_index].find(curr) != box[box_index].end()) //found in 'box[box_index]' set
                    return false;
                row[i].insert(curr); //add curr value in 'row[i]' set
                col[j].insert(curr); //add curr value in 'col[j]' set
                box[box_index].insert(curr); //add curr value in 'box[box_index]' set
            }
        return true;
    }
};