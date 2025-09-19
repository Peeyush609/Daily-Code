class Spreadsheet {
public:
    vector<vector<int>> spreadsheet;
    Spreadsheet(int rows) {
        spreadsheet.resize(rows, vector<int>(26, 0));
    }

    //O(1)
    void setCell(string cell, int value) {
        int col = cell[0] - 'A';
        int row = stoi(cell.substr(1)) - 1;//-1 since 1 based indexing

        spreadsheet[row][col] = value;
    }

    //O(1)
    void resetCell(string cell) {
        setCell(cell, 0);
    }

    //O(1)
    int getValue(string formula) {
        int n = formula.length();
        int a = 0;
        int b = 0;

        int opi = formula.find('+');

        //if the 1st no. is non_negative no.
        if(isdigit(formula[1])){
            a = stoi(formula.substr(1, opi - 1));
        }
        else{
            int col = formula[1] - 'A';
            int row = stoi(formula.substr(2, opi - 1)) - 1;//-1 since 1 based indexing
    
            a = spreadsheet[row][col];
        }

        //if the 2nd no. is non reference no.
        if(isdigit(formula[opi + 1])){
            b = stoi(formula.substr(opi + 1));
        }
        else{
            int col = formula[opi + 1] - 'A';
            int row = stoi(formula.substr(opi + 2)) - 1;//-1 since 1 based indexing
    
            b = spreadsheet[row][col];
        }

        return a + b;
    }
};

/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet* obj = new Spreadsheet(rows);
 * obj->setCell(cell,value);
 * obj->resetCell(cell);
 * int param_3 = obj->getValue(formula);
 */