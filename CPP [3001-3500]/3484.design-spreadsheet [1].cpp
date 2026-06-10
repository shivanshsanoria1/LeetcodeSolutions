class Spreadsheet {
private:
    vector<vector<int>> grid;

    pair<int, int> getCellCoordinates(string str){
        int j = str[0] - 'A';
        int i = stoi(str.substr(1)) - 1;

        return {i, j};
    }

    int getCellValue(string str){
        if(isupper(str[0]))
        {
            auto [i, j] = getCellCoordinates(str);
            return grid[i][j];
        }
        
        return stoi(str);
    }

public:
    Spreadsheet(int rows) {
        this->grid.resize(rows, vector<int>(26, 0));
    }
    
    void setCell(string cell, int value) {
        auto [i, j] = getCellCoordinates(cell);

        grid[i][j] = value;
    }
    
    void resetCell(string cell) {
        auto [i, j] = getCellCoordinates(cell);

        grid[i][j] = 0;
    }
    
    int getValue(string formula) {
        int idx = formula.find("+");
        string x = formula.substr(1, idx - 1);
        string y = formula.substr(idx + 1);

        return getCellValue(x) + getCellValue(y);
    }
};

/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet* obj = new Spreadsheet(rows);
 * obj->setCell(cell,value);
 * obj->resetCell(cell);
 * int param_3 = obj->getValue(formula);
 */