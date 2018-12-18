#include <iostream>

void print(int board[9][9]);

bool solve(int board[9][9]);

bool find_empty_loc(int board[9][9], int &row, int &col);

bool is_legal(int board[9][9], int row, int col, int num);

bool Used_In_Row(int board[9][9], int row, int num);

bool Used_In_Col(int board[9][9], int col, int num);

bool Used_In_Box(int board[9][9], int boxStartRow, int boxStartCol, int num);


int main() {

    int board2[9][9] = {{3, 0, 6, 5, 0, 8, 4, 0, 0},
                        {5, 2, 0, 0, 0, 0, 0, 0, 0},
                        {0, 8, 7, 0, 0, 0, 0, 3, 1},
                        {0, 0, 3, 0, 1, 0, 0, 8, 0},
                        {9, 0, 0, 8, 6, 3, 0, 0, 5},
                        {0, 5, 0, 0, 9, 0, 6, 0, 0},
                        {1, 3, 0, 0, 0, 0, 2, 5, 0},
                        {0, 0, 0, 0, 0, 0, 0, 7, 4},
                        {0, 0, 5, 2, 0, 6, 3, 0, 0}};
    print(board2);

    if (solve(board2) == true)
        print(board2);
    else
        printf("No solution exists");

    return 0;
}

bool solve(int board[9][9]) {

    //print(board);
    int row, col;

    if (!find_empty_loc(board, row, col)) {
        return true;
        //sudoku is solved if there are no empty cells
    }

    //digits from 1-9
    for (int num = 1; num <= 9; ++num) {

        if (is_legal(board, row, col, num)) {


            //make tentative assignment
            board[row][col] = num;

            //return, if sucessful
            if (solve(board)) {
                return true;
            }

            //failed, undo and try again
            board[row][col] = 0;
        }
    }

    return false;
}

bool is_legal(int board[9][9], int row, int col, int num) {
    return (!Used_In_Row(board, row, num) &&
            !Used_In_Col(board, col, num) &&
            !Used_In_Box(board, row - row % 3, col - col % 3, num) &&
            board[row][col] == 0);
}

bool Used_In_Row(int board[9][9], int row, int num) {
    for (int col = 0; col < 9; ++col) {
        if (board[row][col] == num) {
            return true;
        }
    }
    return false;
}

bool Used_In_Col(int board[9][9], int col, int num) {
    for (int row = 0; row < 9; ++row) {
        if (board[row][col] == num) {
            return true;
        }
    }
    return false;
}

bool Used_In_Box(int board[9][9], int boxStartRow, int boxStartCol, int num) {
    for (int col = 0; col < 3; ++col) {
        for (int row = 0; row < 3; ++row) {
            if (board[boxStartRow + row][boxStartCol + col] == num) {
                return true;
            }
        }
    }
    return false;
}

bool find_empty_loc(int board[9][9], int &row, int &col) {
    for (row = 0; row < 9; ++row) {
        for (col = 0; col < 9; ++col) {
            if (board[row][col] == 0) {
                return true;
            }
        }
    }
    return false;
}

void print(int board[9][9]) {
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            if (j % 3 == 0) {
                std::cout << "\t\t";
            }
            std::cout << board[i][j] << "\t";

        }
        if ((i + 1) % 3 == 0) {
            std::cout << std::endl;
        }
        std::cout << std::endl;
    }
    std::cout << "=============================================================\n\n\n";
}