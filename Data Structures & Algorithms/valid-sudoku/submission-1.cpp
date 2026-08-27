class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<int> rows(board.size());
        vector<int> cols(board.size());
        vector<int> cells(board.size());  
        // unordered_map<string, set<string>> rows;
        // unordered_map<string, set<string>> cols;
        // unordered_map<string, set<string>> cells;

        for(int r = 0; r < board.size(); r++){
            for (int c = 0; c < board[0].size(); c++){
                char n = board[r][c];
                if (n == '.'){
                    continue;
                }
                int val = n - '1';
                int rc = (r/3)*3+(c/3);
                if (rows[r] & (1 << val) ||
                    cols[c] & (1 << val) ||
                    cells[rc] & (1 << val)){
                        return false;
                }

                rows[r] |= 1 << val;
                cols[c] |= 1 << val;
                cells[rc] |= 1 << val;
                    
                // if (rows[to_string(r)].contains(num)
                // || cols[to_string(c)].contains(num)
                // || cells[to_string(r/3)+to_string(c/3)].contains(num)){
                //     cout << num<< r/3+c/3 << endl;
                //     return false;
                // }

                // rows[to_string(r)].insert(num);
                // cols[to_string(c)].insert(num);
                // cells[to_string(r/3)+to_string(c/3)].insert(num);
            }
        }
        return true;
    }
};
