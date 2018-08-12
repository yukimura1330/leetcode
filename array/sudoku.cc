/*
判断一个 9x9 的数独是否有效。只需要根据以下规则，验证已经填入的数字是否有效即可。
数字 1-9 在每一行只能出现一次。
数字 1-9 在每一列只能出现一次。
数字 1-9 在每一个以粗实线分隔的 3x3 宫内只能出现一次 
*/

#include <iostream>
#include <vector>

using namespace std;

bool isValidSudoku(vector<vector<char>>& board) {
	int num = 0;
    int col = board.size();
    int row = board[0].size();
    bool colFlag[9][9] = {false};
    bool rowFlag[9][9] = {false};
    bool gridFlag[9][9] = {false};

    for(int i = 0; i < col; i++) {
    	for(int j = 0; j < row; j++) {
    		if(board[i][j] >= '1' && board[i][j] <= '9') {
    			num = board[i][j] - '1';
    			if(colFlag[i][num] || rowFlag[num][j] || gridFlag[3 * (i/3) + (j/3)][num]) {
    				return false;
    			}
    			colFlag[i][num] = true;
    			rowFlag[num][j] = true;
    			gridFlag[3 * (i/3) + (j/3)][num] = true;
    		}
    	}
    }

    return true;
}
int main() {
	vector<char> vec1 = {'.','.','5','.','.','.','.','.','6'};
	vector<char> vec2 = {'.','.','.','.','1','4','.','.','.'};
	vector<char> vec3 = {'.','.','.','.','.','.','.','.','.'};
	vector<char> vec4 = {'.','.','.','.','.','9','2','.','.'};
	vector<char> vec5 = {'5','.','.','.','.','2','.','.','.'};
	vector<char> vec6 = {'.','.','.','.','.','.','.','3','.'};
	vector<char> vec7 = {'.','.','.','5','4','.','.','.','.'};
	vector<char> vec8 = {'3','.','.','.','.','.','4','2','.'};
	vector<char> vec9 = {'.','.','.','2','7','.','6','.','.'};							
	vector<vector<char>> board = {vec1, vec2, vec3, vec4, vec5, vec6, vec7, vec8, vec9};
	cout << "Sudoku=" << isValidSudoku(board) << endl;
	return 0;
}