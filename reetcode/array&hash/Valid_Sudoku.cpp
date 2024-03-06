
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
		// column, row, sub_box에서 1-9에서 중복이 없어야한다.
		vector<unordered_set<int>> row_set(9);
		vector<unordered_set<int>> col_set(9);
		vector<unordered_set<int>> sub_box_set(9);

		for(int i=0; i<9; i++){
			for(int j=0; j<9; j++){
				if(board[i][j] == ".")
					continue;
				if(row_set[i].find(board[i][j]) != row_set[i].end())
					return (false);
				else if(col_set[j].find(board[i][j]) != col_set[j].end())
					return (false);
				else if(sub_box_set[(i/3)*3 + j/3].find(board[i][j]) != sub_box_set[(i/3)*3 + j/3].end())
					return (false);

				row_set[i].insert(board[i][j]);
				col_set[j].insert(board[i][j]);
				sub_box_set[(i/3)*3 + j/3].insert(board[i][j]);
			}
		}
		return (true);
	}
};


// ex1.
// Input: board = 
// [["5","3",".",".","7",".",".",".","."]
// ,["6",".",".","1","9","5",".",".","."]
// ,[".","9","8",".",".",".",".","6","."]
// ,["8",".",".",".","6",".",".",".","3"]
// ,["4",".",".","8",".","3",".",".","1"]
// ,["7",".",".",".","2",".",".",".","6"]
// ,[".","6",".",".",".",".","2","8","."]
// ,[".",".",".","4","1","9",".",".","5"]
// ,[".",".",".",".","8",".",".","7","9"]]
// Output: true
